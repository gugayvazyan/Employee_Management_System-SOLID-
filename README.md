# 💼 Employee Payroll System (C++)

A small, clean OOP project that demonstrates **inheritance**, **interfaces**, **runtime polymorphism**, and **basic repository/service architecture** for calculating and paying salaries.

> ✅ Target: **C++17**  
> 🧠 Key ideas: `virtual`, `dynamic_cast`, `std::shared_ptr`, separation into `.h/.cpp`

---

## ✨ What this project does

- Stores employees in a repository (`EmployeeRepository`)
- Supports multiple employee roles (Developer, Manager, Accountant, SalesPerson, President)
- Calculates payroll through a service (`PayrollService`)
- Pays only employees that implement the **salary interface** (`ISalaried`)
- After payment, **resets** monthly counters (projects/decisions/reports/sales) using `clean()`

---

## 🧩 Architecture

### Core building blocks

| Component | Type | Responsibility |
|---|---|---|
| `Employee` | Abstract base class | Common fields (id, name) + `printInfo()` |
| `ISalaried` | Interface | Salary contract: `Calculate()` and monthly `clean()` |
| `EmployeeRepository` | Repository | Stores employees: `addEmpl`, `delEmpl`, `listEmpl` |
| `PayrollService` | Service | Iterates repository and pays **only** `ISalaried` employees |

### Runtime salary selection (important!)

Payroll uses:

- `dynamic_cast<ISalaried*>(emp.get())` ✅

So employees like **President** (who does not implement `ISalaried`) are **skipped automatically**.

---

## 👥 Employee roles & salary rules

| Role | Implements `ISalaried` | Rule (Base + Bonus) | Monthly counter |
|---|---:|---|---|
| 👨‍💻 Developer | ✅ | `1,500,000 + projects * 100,000` | projects (`pcount`) |
| 🧑‍💼 Manager | ✅ | `1,000,000 + decisions * 100,000` | decisions (`dcount`) |
| 🧾 Accountant | ✅ | `400,000 + reports * 30,000` | reports (`rcount`) |
| 🛒 SalesPerson | ✅ | `600,000 + sales * 75,000` | sales (`scount`) |
| 👑 President | ❌ | Printed as “Infinity” (not paid by payroll) | — |

> 💡 After `PayrollService::Pay(...)`, salaried roles call `clean()` to reset their counters to `0`.

---

## 📁 Files (overview)

| File | Purpose |
|---|---|
| `Employee.h/.cpp` | Abstract employee base + auto-incrementing id |
| `ISalaried.h/.cpp` | Salary interface (contract) |
| `Developer.h/.cpp` | Developer role + projects logic |
| `Manager.h/.cpp` | Manager role + decisions logic |
| `Accountant.h/.cpp` | Accountant role + reports logic |
| `SalesPerson.h/.cpp` | Sales role + sales logic |
| `President.h/.cpp` | President role (non-salaried) |
| `EmployeeRepository.h/.cpp` | Repository storage using `std::shared_ptr<Employee>` |
| `PayrollService.h/.cpp` | Payroll calculation + `dynamic_cast` filtering |

---

---
## 🌳 Project Tree
.
├── Makefile
├── include
│   ├── Accountant.h
│   ├── Developer.h
│   ├── Employee.h
│   ├── EmployeeRepository.h
│   ├── ISalaried.h
│   ├── Manager.h
│   ├── PayrollService.h
│   ├── President.h
│   └── SalesPerson.h
└── src
    ├── Accountant.cpp
    ├── Developer.cpp
    ├── Employee.cpp
    ├── EmployeeRepository.cpp
    ├── ISalaried.cpp
    ├── Manager.cpp
    ├── PayrollService.cpp
    ├── President.cpp
    ├── SalesPerson.cpp
    └── main.cpp

---

## ⚙️ Build & Run (Makefile)

This project includes a simple Makefile that automatically builds all `*.cpp` files and puts object files into `build/`.

### ✅ Build
```bash
make
✅ Run
./vayvay
✅ Clean
make clean

---

## ▶️ Minimal example (`main.cpp`)

Create a simple `main.cpp` next to the sources:

```cpp
#include <memory>
#include "EmployeeRepository.h"
#include "PayrollService.h"

#include "Developer.h"
#include "Manager.h"
#include "Accountant.h"
#include "SalesPerson.h"
#include "President.h"

int main() {
    EmployeeRepository repo;

    repo.addEmpl(std::make_shared<Developer>("Alice", 3));
    repo.addEmpl(std::make_shared<Manager>("Bob", 2));
    repo.addEmpl(std::make_shared<Accountant>("Charlie", 5));
    repo.addEmpl(std::make_shared<SalesPerson>("Diana", 4));
    repo.addEmpl(std::make_shared<President>("Mr. President"));

    // Print all employees
    repo.listEmpl();

    // Pay everyone who is ISalaried
    PayrollService payroll;
    payroll.Pay(repo);

    // Counters are reset after payment
    repo.listEmpl();

    return 0;
}
```

---

## 🧪 Notes (good to know)

- Memory ownership is simple and safe thanks to `std::shared_ptr<Employee>` ✅
- `Employee::printInfo()` is pure virtual, so every role must implement it ✅
- `PayrollService` accesses repository storage (it is declared as a `friend`) 🔐

---

## 🗺️ Next improvements (optional)

- Add input validation and richer error messages
- Fix `delEmpl()` so it prints “ID not found” only once (after the loop)
- Add unit tests for salary formulas
- Add a menu-driven CLI for HR operations (add/list/delete/pay)

---

## 📜 License

This project is intended for learning and educational purposes.

