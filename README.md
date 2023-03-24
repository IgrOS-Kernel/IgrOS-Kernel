# IgrOS-Kernel [![Badge-CPP]][Link-CPP]

IgrOS-Kernel is a simple **OS kernel** written in **C++20**.
Currently supports **i386** and **x86_64** platforms. **ARM** and **AVR** are the next aims.

---

## Project stats:

[![Badge-License]][Link-License]
[![Badge-GitHub]][Link-GitHub]
[![Badge-GitLab]][Link-GitLab]
[![Badge-Azure-DevOps]][Link-Azure-DevOps]
[![Codacy branch grade](https://img.shields.io/codacy/grade/1a4425daf2a946448a3d9c915c25da71/master?label=CODACY%20QUALITY&style=for-the-badge&logo=Codacy)](https://app.codacy.com/gh/IGR2014/IgrOS-Kernel/dashboard)
[![Codacy Coverage](https://img.shields.io/codacy/coverage/1a4425daf2a946448a3d9c915c25da71/master?label=Codacy%20Coverage&style=for-the-badge&logo=Codacy)](https://app.codacy.com/gh/IGR2014/IgrOS-Kernel/dashboard)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=IGR2014_IgrOS-Kernel&metric=security_rating)](https://sonarcloud.io/dashboard?id=IGR2014_IgrOS-Kernel)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=IGR2014_IgrOS-Kernel&metric=alert_status)](https://sonarcloud.io/dashboard?id=IGR2014_IgrOS-Kernel)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=IGR2014_IgrOS-Kernel&metric=reliability_rating)](https://sonarcloud.io/dashboard?id=IGR2014_IgrOS-Kernel)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=IGR2014_IgrOS-Kernel&metric=bugs)](https://sonarcloud.io/dashboard?id=IGR2014_IgrOS-Kernel)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=IGR2014_IgrOS-Kernel&metric=coverage)](https://sonarcloud.io/dashboard?id=IGR2014_IgrOS-Kernel)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=IGR2014_IgrOS-Kernel&metric=duplicated_lines_density)](https://sonarcloud.io/dashboard?id=IGR2014_IgrOS-Kernel)
[![Lines of Code](https://sonarcloud.io/api/project_badges/measure?project=IGR2014_IgrOS-Kernel&metric=ncloc)](https://sonarcloud.io/dashboard?id=IGR2014_IgrOS-Kernel)

---

## Implemented features:

| Feature                    |       Status       |
| :---                       |       :---:        |
| **Custom bootloader**      |                    |
| **Multiboot**              | :heavy_check_mark: |
| **Multiboot 2**            |                    |
| **GDT**                    | :heavy_check_mark: |
| **IDT**                    | :heavy_check_mark: |
| **Exceptions**             | :heavy_check_mark: |
| **Interrupts**             | :heavy_check_mark: |
| **Paging**                 | :heavy_check_mark: |
| **Phys. page allocator**   | :heavy_check_mark: |
| **Virt. memory allocator** |                    |
| **VGA driver (text mode)** | :heavy_check_mark: |
| **PIT driver**             | :heavy_check_mark: |
| **Keyboard driver (read)** | :heavy_check_mark: |
| **CMOS RTC driver (read)** | :heavy_check_mark: |
| **User mode**              |                    |
| **Kernel drivers**         |                    |
| **User programs**          |                    |
| **GUI**                    |                    |

---

### ***P.S.:***
###### ***Developed and maintained by Igor Baklykov (c) 2017 - 2021***


[Badge-Azure-DevOps]: https://img.shields.io/azure-devops/build/prigoryan/1dea483f-6c7a-4efb-8631-5309fd3370ec/4/master?label=CI%2FCD%20Azure%20DevOps&style=for-the-badge&logo=Azure%20DevOps
[Badge-CPP]: https://img.shields.io/static/v1?label=STANDARD&message=C%2B%2B20&color=blue&style=for-the-badge&logo=C%2B%2B
[Badge-GitHub]: https://img.shields.io/github/actions/workflow/status/IGR2014/IgrOS-Kernel/github-ci.yml?branch=master&label=CI%2FCD%20GitHub&style=for-the-badge&logo=GitHub
[Badge-GitLab]: https://img.shields.io/gitlab/pipeline-status/IGR2014/IgrOS-Kernel?branch=master&label=CI%2FCD%20GitLab&style=for-the-badge&logo=GitLab
[Badge-License]: https://img.shields.io/github/license/IGR2014/IgrOS-Kernel?label=License&style=for-the-badge&logo=Open%20Source%20Initiative

[Link-Azure-DevOps]: https://dev.azure.com/prigoryan/IgrOS-Kernel/_build/latest?definitionId=4&branchName=master
[Link-CPP]: https://en.cppreference.com/w/cpp/20
[Link-GitHub]: https://github.com/IGR2014/IgrOS-Kernel/actions
[Link-GitLab]: https://gitlab.com/IGR2014/IgrOS-Kernel/-/commits/master
[Link-License]: https://opensource.org/licenses/MIT
