# OrbitalMissionSim

##  Orbital Visualization Engine (C++ / SFML)

### Real-Time Multi-Satellite Orbital Simulation & Visualization Engine

A real-time orbital mechanics visualization engine built in **C++**, designed to simulate and render multi-satellite orbital motion using physics-based propagation and real-time rendering architecture.

This project focuses on combining **numerical physics simulation**, **real-time rendering**, and **simulation engine architecture** — similar to foundational components used in aerospace simulation software and mission visualization tools.


## Key Features

### Orbital Simulation

* Multi-satellite real-time orbit propagation
* Physics-based motion (Newtonian gravity)
* Adjustable simulation time scaling
* Orbit plane tilt visualization


### Real-Time Rendering Engine

* Stable game-engine style render loop
* Event loop separation (industry architecture)
* Real-time satellite visualization
* Orbit trail rendering per satellite

### Visualization System

* Per-satellite colored orbit trails
* Satellite ID labeling
* Earth body rendering with real-scale zoom
* Camera pan (WASD)
* Mouse wheel zoom

### Data & Analysis

* Orbit state CSV export
* Real-time state logging capability
* Simulation time tracking

## Engineering Concepts Demonstrated

* Real-time simulation loop design
* Physics update vs render separation
* Coordinate system scaling (world → screen)
* Entity-component style simulation architecture
* Numerical simulation stability thinking
* Graphics pipeline debugging
* Event driven rendering architecture

## Tech Stack

| Domain       | Technology                  |
| ------------ | --------------------------- |
| Language     | C++                         |
| Rendering    | SFML 3                      |
| Physics      | Newtonian Gravity           |
| Math         | Custom Vector Math          |
| Data         | CSV Logging                 |
| Architecture | Real-Time Simulation Engine |

## Architecture Overview

```
Simulation Layer
 ├ Satellite Physics State
 ├ Constellation Manager
 └ Numerical Propagation

Rendering Layer
 ├ Camera System
 ├ Earth Renderer
 ├ Satellite Renderer
 └ Trail Renderer

Data Layer
 ├ CSV Logging
 └ Simulation Time Tracking
```

## Example Capabilities

* Multi-sat constellation visualization
* Orbit plane separation visualization
* Real-time zoomable Earth-orbit system
* Interactive simulation camera navigation

## Future Roadmap

* TLE + SGP4 propagation module (separate project)
* Ground track visualization
* Ground station pass prediction
* OpenGL 3D orbital rendering
* Constellation mission planning visualization
* Real mission timeline playback

## Motivation

This project is part of a long-term engineering path toward **spaceflight dynamics software and mission simulation systems**.

Focus areas include:

* Orbital mechanics simulation
* Numerical integrator implementation
* Real-time physics visualization
* Aerospace software architecture

##  Author

Physics student focused on orbital simulation, numerical physics software, and space systems engineering.
