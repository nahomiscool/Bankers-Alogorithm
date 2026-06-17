# Banker's Algorithm - Deadlock Avoidance

## 📌 Overview
This project implements the **Banker's Algorithm**, a classic deadlock avoidance algorithm in operating systems. Named after the banking system analogy, it ensures that a system remains in a safe state by carefully allocating resources to processes, preventing deadlocks before they occur.

## 🎯 What is the Banker's Algorithm?
The Banker's Algorithm is a resource allocation and deadlock avoidance algorithm that tests whether granting a resource request to a process would lead to an unsafe state. If the system would remain in a safe state, the request is granted; otherwise, the process must wait.

### Key Concepts:
- **Available**: Resources currently available in the system
- **Max**: Maximum resources each process may need
- **Allocation**: Resources currently allocated to each process
- **Need**: Remaining resources each process needs (Max - Allocation)
- **Safe State**: A state where there is at least one safe sequence of process execution

## 📋 Features
- ✅ Input validation for resource requests
- ✅ Safety algorithm implementation to detect safe/unsafe states
- ✅ Resource request algorithm to grant or deny requests
- ✅ Real-time status display of system state
- ✅ User-friendly interface for testing different scenarios

## 🚀 Getting Started

### Prerequisites
- Git
- C++ compiler/interpreter(g++)
- VS Code (recommended) or any text editor

### Installation & Setup
```bash
# Clone the repository
git clone https://github.com/nahomiscool/Bankers-Algorithm.cpp

# Navigate to project directory
cd Bankers-Algorithm
```

# Run the program
[your execution command]

Sample Usage
# Example input
Number of processes: 5
Number of resource types: 3
Available resources: 3 3 2

# Process details
Process P0: Max = 7 5 3, Allocation = 0 1 0
Process P1: Max = 3 2 2, Allocation = 2 0 0
Process P2: Max = 9 0 2, Allocation = 3 0 2
Process P3: Max = 2 2 2, Allocation = 2 1 1
Process P4: Max = 4 3 3, Allocation = 0 0 2

# Resource request example
Process P1 requests: 1 0 2


💻 Code Structure
bankers-algorithm/
├── src/
│   ├── main.py          # Main execution file
│   ├── bankers.py       # Core algorithm implementation
│   └── utils.py         # Helper functions
├── tests/
│   └── test_cases.py    # Unit tests
├── README.md
└── LICENSE

🔍 How It Works
1. Safety Algorithm

Checks if the system is in a safe state by finding a safe sequence of processes that can complete execution.
2. Resource Request Algorithm

When a process requests resources:

   1. Verify request ≤ Need

   2. Verify request ≤ Available

   3. Temporarily allocate resources

   4. Run safety algorithm

   5. If safe → grant request, else → deny and rollback
      
📊 Example Output
     System State:
  Available: [3, 3, 2]
  
  Process    Allocation    Max         Need
  P0         [0, 1, 0]    [7, 5, 3]   [7, 4, 3]
  P1         [2, 0, 0]    [3, 2, 2]   [1, 2, 2]
  P2         [3, 0, 2]    [9, 0, 2]   [6, 0, 0]
  P3         [2, 1, 1]    [2, 2, 2]   [0, 1, 1]
  P4         [0, 0, 2]    [4, 3, 3]   [4, 3, 1]
  
  ✅ System is in SAFE state.
  Safe sequence: P1 → P3 → P4 → P0 → P2


  🧪 Test Scenarios

    Safe State: All processes can complete execution

    Unsafe State: Potential deadlock exists

    Resource Request: Process requests additional resources

    Edge Cases: Zero resources, maximum allocation scenarios

📚 Learning Outcomes

    Understanding of deadlock avoidance principles

    Implementation of the Banker's Algorithm

    Resource allocation strategies in operating systems

    Safe state detection and prevention techniques

🤝 Contributing

    Fork the repository

    Create a feature branch (git checkout -b feature/amazing-feature)

    Commit changes (git commit -m 'Add amazing feature')

    Push to branch (git push origin feature/amazing-feature)

    Open a Pull Request

📝 License

This project is licensed under the MIT License - see the LICENSE file for details.
👤 Author

Your Name

    GitHub: @nahomiscool

    LinkedIn: www.linkedin.com/in/nahom-zewdu-295704332

🙏 Acknowledgments

    Operating Systems course instructors

    Contributors and testers

📧 Contact

For questions or suggestions, please open an issue or reach out directly.

⭐ Star this repository if you found it helpful!
