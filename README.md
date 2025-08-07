# StoneDrill PhysicalDrive Fucker!
- Shamoon's cousin: Shamoon emerged in 2012 and targeted the energy sector for sabotage, destroying hard drives by overwriting critical sectors and deleting the MBR, rendering systems unusable. It uses basic propagation techniques via stolen credentials and SMB, with no persistence or advanced communication.

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
