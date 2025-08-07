# StoneDrill PhysicalDrive Fucker!
- Shamoon's cousin: Shamoon emerged in 2012 and targeted the energy sector for sabotage, destroying hard drives by overwriting critical sectors and deleting the MBR, rendering systems unusable. It uses basic propagation techniques via stolen credentials and SMB, with no persistence or advanced communication.
- Stonedrill's tories: StoneDrill is a more recent and sophisticated variant (detected in 2018-2019) that maintains the same destructive intent but employs more advanced methods: it overwrites multiple disk areas, deletes backups, uses encryption to hide its modules, communicates with C2 servers to receive commands, and can persist on the system. It also employs more complex evasion and propagation techniques.

## T1485 Data Destruction
Adversaries may destroy data and files on specific systems or in large numbers on
a network to interrupt availability to systems, services, and network resources.
Data destruction is likely to render stored data irrecoverable by forensic techniques
through overwriting files or data on local and remote drives.
(Citation: Symantec Shamoon 2012)
(Citation: FireEye Shamoon Nov 2016)
(Citation: Palo Alto Shamoon Nov 2016)
(Citation: Kaspersky StoneDrill 2017)
(Citation: Unit 42 Shamoon3 2018)
(Citation: Talos Olympic Destroyer 2018) 
Common operating system file deletion commands such as <code>del</code> and <code>rm</code>
often only remove pointers to files without wiping the contents of the files themselves,
making the files recoverable by proper forensic methodology. This behavior is distinct from
[Disk Content Wipe](https://attack.mitre.org/techniques/T1561/001/) and [Disk Structure Wipe](https://attack.mitre.org/techniques/T1561/002/) because individual files are destroyed rather than sections of a storage disk or the disk's logical structure.

### NIST 800-53 Mappings:
| Capability ID | Capability Description                       | Mapping Type | ATT&CK ID | ATT&CK Name      | Notes            |
|---------------|---------------------------------------------|--------------|-----------|------------------|------------------|
| AC-3          | Access Enforcement                          | Protects     | T1485     | Data Destruction |                  |
| AC-6          | Least Privilege                            | Protects     | T1485     | Data Destruction |                  |
| CM-2          | Baseline Configuration                     | Protects     | T1485     | Data Destruction |                  |
| CP-10         | System Recovery and Reconstitution        | Protects     | T1485     | Data Destruction |                  |
| CP-2          | Contingency Plan                           | Protects     | T1485     | Data Destruction |                  |
| CP-7          | Alternate Processing Site                  | Protects     | T1485     | Data Destruction |                  |
| CP-9          | System Backup                             | Protects     | T1485     | Data Destruction |                  |
| SI-3          | Malicious Code Protection                  | Protects     | T1485     | Data Destruction |                  |
| SI-4          | System Monitoring                         | Protects     | T1485     | Data Destruction |                  |
| SI-7          | Software, Firmware, and Information Integrity | Protects | T1485     | Data Destruction |                  |

> [!IMPORTANT]\
> This method detects a service install of the malicious Microsoft Network Realtime Inspection Service service described in StoneDrill report by Kaspersky
