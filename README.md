# 📦 Static Memory Safe Ring Buffer  
**MISRA C:2012 | Deterministic | Mission-Critical**

A reliable, static-memory **Ring Buffer (Circular Buffer)** library for embedded and defense systems.  
No dynamic memory is used, ensuring predictable execution and avoiding fragmentation.

---

## 🚀 Features
- **Static Memory Only** – no `malloc` / `free`.  
- **MISRA C:2012 Compliant** – safe coding standards.  
- **Thread & ISR Safe** – works across interrupts and RTOS tasks.  
- **Defensive Checks** – null pointer and boundary protection.  
- **Constant Time** – O(1) for read/write.

---

## 📂 Structure
```text
Project1_Static_RingBuffer/
├── include/   # Public headers
├── src/       # Core implementation
├── tests/     # Unit tests
├── Makefile   # Build rules
└── .github/   # CI/CD configs
```

---

## 📐 Requirements
- **Static Allocation** – buffers fixed at compile time.  
- **Status Codes** – all APIs return explicit results.  
- **Overflow Protection** – full buffer rejects new writes.  
- **Underflow Protection** – empty buffer read fails safely.  
- **Null Defense** – invalid references return error.

---

## 🧪 Testing & CI
- Unit tests for normal, edge, and error cases.  
- Target: 100% statement & branch coverage.  
- CI/CD runs:  
  - Strict compilation checks  
  - Static analysis (Cppcheck / SonarQube)  
  - Automated test suite  

---

## 🎯 Applications
- Aerospace & defense embedded software  
- Avionics modules  
- RTOS components  
- Safety-certified industrial controllers  
```