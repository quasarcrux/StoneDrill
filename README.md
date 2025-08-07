> ## Description

> This method detects a service install of the malicious Microsoft Network Realtime Inspection Service service described in StoneDrill report by Kaspersky. This rule is adapted from https://github.com/SigmaHQ/sigma/blob/master/rules/windows/builtin/system/service_control_manager/win_system_apt_stonedrill.yml

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

```yaml
title: StoneDrill Service Install
id: 9e987c6c-4c1e-40d8-bd85-dd26fba8fdd6
status: test
description: This method detects a service install of the malicious Microsoft Network Realtime Inspection Service service described in StoneDrill report by Kaspersky
references:
    - https://securelist.com/blog/research/77725/from-shamoon-to-stonedrill/
author: Florian Roth (Nextron Systems)
date: 2017-03-07
modified: 2021-11-30
tags:
    - attack.persistence
    - attack.g0064
    - attack.t1543.003
    - detection.emerging-threats
logsource:
    product: windows
    service: system
detection:
    selection:
        Provider_Name: 'Service Control Manager'
        EventID: 7045
        ServiceName: NtsSrv
        ImagePath|endswith: ' LocalService'
    condition: selection
falsepositives:
    - Unlikely
level: high
```

## MITRE ATT&CK® Tactics
Persistence consists of techniques that adversaries use to keep access to systems across restarts, changed credentials, and other interruptions that could cut off their access. Techniques used for persistence include any access, action, or configuration changes that let them maintain their foothold on systems, such as replacing or hijacking legitimate code or adding startup code.
### https://attack.mitre.org/tactics/TA0003

## MITRE ATT&CK® Techniques (T1543.003)
<h5 align="left">Create or Modify System Process: Windows Service ....</h5>

###

*Adversaries may create or modify Windows services to repeatedly execute malicious payloads as part of persistence. When Windows boots up, it starts programs or applications called services that perform background system functions. Adversaries may install a new service or modify an existing service by using system utilities to interact with services, by directly modifying the Registry, or by using custom tools to interact with the Windows API. Adversaries may configure services to execute at startup in order to persist on a system. An adversary may also incorporate Masquerading by using a service name from a related operating system or benign software, or by modifying existing services to make detection analysis more challenging. Modifying existing services may interrupt their functionality or may enable services that are disabled or otherwise not commonly used. Services may be created with administrator privileges but are executed under SYSTEM privileges, so an adversary may also use a service to escalate privileges from administrator to SYSTEM.*

## Fountain:
[Kapersky: "De Shamoon a StoneDrill – Un nuevo malware destructivo hace aparición"](https://www.kaspersky.es/about/press-releases/de-shamoon-a-stonedrill-un-nuevo-malware-destructivo-hace-aparicion)

[MITRE ATT&CK®: "StoneDrill is wiper malware discovered in destructive campaigns against both Middle Eastern and European targets in association with APT33"](https://attack.mitre.org/software/S0380/)

[S E R I N F O R: "StoneDrill, el wiper que borra los discos duros dejándolos vacíos"](https://www.serinfor.net/stonedrill-el-wiper-que-borra-los-discos-duros-dejandolos-vacios/)

[MalPedia](https://malpedia.caad.fkie.fraunhofer.de/details/win.stonedrill)

[Microsoft: "Trojan:Win32/StoneDrill!pz"](https://www.microsoft.com/en-us/wdsi/threats/malware-encyclopedia-description?Name=Trojan:Win32/StoneDrill!pz&ThreatID=2147894934)

[KasperskyContentHub "FROM SHAMOON TO STONEDRILL"](https://media.kasperskycontenthub.com/wp-content/uploads/sites/43/2018/03/07180722/Report_Shamoon_StoneDrill_final.pdf)
