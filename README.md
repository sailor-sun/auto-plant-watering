# Minor Project Lab Report: Automated Plant Watering

## Introduction
The **Automatic Plant Watering System** is an automated irrigation system using **Java** and **Arduino**, implementing a state machine with real-time updates via **TimerTask** to autonomously water a plant by monitoring soil moisture levels. The system uses a **moisture sensor** to detect if the soil is too dry, and when the moisture drops below a certain threshold, the system activates a pump to water the plant. The status of the system, including whether the soil is adequately watered, is displayed on an **OLED** screen. This device is especially useful for scenarios such as vacations, where the plant needs to be watered without any human intervention. The system ensures that the plant is watered automatically as long as the water reservoir has sufficient water.


---

## Technical Requirements / Specifications
- The soil moisture sensor detects soil moisture.
- If the soil is dry, the water pump turns on.
- If the soil is sufficiently moist, the pump stays off.

---

## Components List
- Arduino board
- Soil moisture sensor
- MOSFET driver
- Water pump
- Red LED
- Push button
- Display (U8x8 library compatible)

![Plant watering setup](project_setup.png)


---

## Demo
https://www.youtube.com/watch?v=EAGWkbteVIQ
https://www.youtube.com/watch?v=scSwdowvu3I

> **Note:** This project was completed earlier but is being uploaded now for record-keeping. (2021)
