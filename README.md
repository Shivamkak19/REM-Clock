<a name="readme-top"></a>

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Shivamkak19/REM-Clock">
    <img src="images/logo1.png" alt="Logo">
  </a>

<h3 align="center">Project Description</h3>

Have you ever wanted to optimize the sleep you get at night? From service staff working night shifts to doctors staffing the emergency room to athletes on professional training cycles, many people in society only have a limited window of time in which they can get the sleep they need for the night.

What if there was a way to guarantee restful sleep during this window of time?

Sleep therapists recommend waking from sleep after completion of a REM cycle, which is the latter half of the general sleep cycle. The REM-Clock sets an alarm that wakes up users after an input REM sleep cycle count to maximize restful sleep for users. `

<br />

<a href="https://github.com/Shivamkak19/REM-Clock/images">View Product</a>
·
<a href="https://github.com/Shivamkak19/REM-Clock/issues">Report Bug</a>
·
<a href="https://github.com/Shivamkak19/REM-Clock/issues">Request Feature</a>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## Project Design

![Product Name Screen Shot][product-screenshot]
<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

* [![C++][cplusplus]][cplusplus-url]
* [![Arduino][arduino]][arduino-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

Below, we have included the set up process for running the arduino code. For set up process of the hardware with Arduino Uno, heart rate chip, and LED panel, please see REPORT.md.

### Prerequisites

To run this project, you must download the latest version of the Arduino IDE (2.1.1). 
Download here: https://www.arduino.cc/en/software

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Shivamkak19/REM-Clock.git
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

Once the source code is uploaded onto an Arduino Uno, the user must strap their finger into the heart rate monitor finger clasp. The LED panel will display important information regarding REM sleep cycle count and current heart rate. 

The alarm will ring after the input REM cycle count has elapsed. 

![Product Name Screen Shot][product-screenshot2]
![Product Name Screen Shot][product-screenshot3]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [ ] Configure Circuit Design
- [ ] Design algorithm for locating REM sleep cycles
- [ ] Collect user input for desired quantity of REM sleep cycles
    - [ ] Set alarm accordingly

See the [open issues](https://github.com/Shivamkak19/REM-Clock/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributing

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/newFeature`)
3. Commit your Changes (`git commit -m 'Add some new feature to REM-Clock'`)
4. Push to the Branch (`git push origin feature/newFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

* Shivam Kak: sk3686@princeton.edu
* Maxwell Lin: ml7013@princeton.edu
* Project Link: [https://github.com/Shivamkak19/REM-Clock](https://github.com/Shivamkak19/REM-Clock)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* []() Hossein Valavi, professor of Electrical Engineering at Princeton, for instruction of ECE 203 circuit analysis as well as support throughout the building process.
* []() David Radcliff, Undergraduate Lab Manager @ Princeton Engineering, for assistance in debugging hardware issues and instruction in proper usage of electrical equipment.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Shivamkak19/REM-Clock.svg?style=for-the-badge
[contributors-url]: https://github.com/Shivamkak19/REM-Clock/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Shivamkak19/REM-Clock.svg?style=for-the-badge
[forks-url]: https://github.com/Shivamkak19/REM-Clock/network/members
[stars-shield]: https://img.shields.io/github/stars/Shivamkak19/REM-Clock.svg?style=for-the-badge
[stars-url]: https://github.com/Shivamkak19/REM-Clock/stargazers
[issues-shield]: https://img.shields.io/github/issues/Shivamkak19/REM-Clock.svg?style=for-the-badge
[issues-url]: https://github.com/Shivamkak19/REM-Clock/issues
[license-shield]: https://img.shields.io/github/license/Shivamkak19/REM-Clock.svg?style=for-the-badge
[license-url]: https://github.com/Shivamkak19/REM-Clock/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/shivamkak
[product-screenshot]: images/product-1.jpg
[product-screenshot2]: images/product-2.jpg
[product-screenshot3]: images/product-3.jpg

<!-- Programming Language Shields -->
[cplusplus]:  https://img.shields.io/badge/C++-00427e?style=for-the-badge&logo=cplusplus&logoColor=61DAFB
[cplusplus-url]: https://cplusplus.com/

[arduino]: https://img.shields.io/badge/Arduino-008183?style=for-the-badge&logo=arduino&logoColor=000000
[arduino-url]: https://www.arduino.cc/
