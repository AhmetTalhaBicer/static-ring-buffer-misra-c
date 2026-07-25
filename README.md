# 📦 Static Memory Safe Ring Buffer Library  
**MISRA C:2012 Compliant | Deterministic | Mission-Critical**

A high-reliability, static-memory-allocated **Ring Buffer (Circular Buffer)** library designed for mission-critical embedded systems and defense industry applications (e.g., DO-178C certification target).

This repository completely eliminates dynamic memory allocation to prevent runtime determinism loss, memory fragmentation, and unpredictable execution delays.

---

## 🚀 Architectural Highlights

- **Zero Dynamic Memory Allocation**  
  Avoids `malloc` and `free` to guarantee deterministic execution time and prevent memory fragmentation.

- **MISRA C:2012 Standard Adherence**  
  Developed in strict accordance with aerospace and defense coding guidelines.

- **Thread & Interrupt Safety**  
  Control variables are qualified for safe, asynchronous data transfer between ISRs and RTOS tasks.

- **Defensive Programming**  
  Implements strict boundary checking and pointer validation against null reference errors.

- **Deterministic Execution**  
  Guarantees constant time complexity **O(1)** for both data ingestion and retrieval operations.

---

## 🏛️ Project Directory Structure

```text
Project1_Static_RingBuffer/
├── include/       # Public API headers, status enumerations, and module interfaces
├── src/           # Implementation of core ring buffer logic and validation
├── tests/         # Unit test suite and boundary verification scripts
├── Makefile       # Cross-compilation scripts and local test execution rules
└── .github/       # Continuous Integration (CI) pipeline configurations
```

---

## 📐 Low-Level Requirements (LLR - DO-178C Traceability)

- **REQ-STATIC-MEM**  
  The module shall allocate all memory buffers at compile-time and must not invoke dynamic memory allocation routines.

- **REQ-STATUS-REPORT**  
  Every public interface routine shall return an explicit status code indicating operation outcome.

- **REQ-OVERFLOW-PROT**  
  When the buffer reaches full capacity, additional write attempts shall be rejected with a full status warning without corrupting existing data.

- **REQ-UNDERFLOW-PROT**  
  Read operations on an empty buffer shall fail gracefully without mutating destination structures.

- **REQ-NULL-DEFENSE**  
  Invoking any public routine with an invalid or uninitialized reference shall immediately yield a null error status code.

---

## 🧪 Verification, Testing & DevOps Pipeline

### Testing Strategy
- **Unit Testing**: Comprehensive test cases covering normal operation, boundary conditions, and invalid input scenarios.  
- **Coverage Target**: Formatted to achieve **100% statement and branch coverage** on core logic.

### Automated CI/CD Pipeline (GitHub Actions)
On every push or pull request, the pipeline executes:

1. **Compilation Check**  
   Compiles using strict warning and error flags to ensure clean code execution.

2. **Static Code Analysis**  
   Scans the codebase using tools (Cppcheck / SonarQube) against MISRA C:2012 compliance.

3. **Automated Test Execution**  
   Runs the unit test suite and validates requirement verification before permitting merge operations.

---

## 🛡️ Target Applications
- Aerospace & Defense Embedded Systems  
- Avionics Software Modules  
- Mission-Critical RTOS Components  
- Safety-Certified Industrial Controllers  
