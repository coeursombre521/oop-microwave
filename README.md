# oop_microwave

This is a C++ application that simulates a microwave using object-oriented programming principles. It implements design patterns such as Singleton, State, and Observer. The application is built using C++, Meson, and GLFW with ImGui for its user interface.

## Design patterns
- **Singleton**: This pattern ensures that a class has only one instance and provides a global point of access to it. In this application, the `CountdownContext` class is implemented as a Singleton.
- **State**: This pattern allows an object to alter its behavior when its internal state changes. The object will appear to change its class. In this application, the microwave cycles through different states: `StateDoorOpened`, `StateDoorClosed`, and `StateCooking`.
- **Observer**: This pattern defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. In this application, the `CountdownContext` class notifies the current state when the countdown changes.

## Folder Structure

- `src/`: Contains the source code of the application.
  - `app_impl/`: Contains the implementation of the application.
  - `base_type/`: Contains the base types used in the application.
  - `context/`: Contains the context classes.
  - `entity/`: Contains the entity classes.
  - `material/`: Contains the material classes.
  - `model/`: Contains the model classes.
  - `state/`: Contains the state classes.
  - `ui/`: Contains the user interface classes.
- `include/`: Contains the header files
  - `microwave/`: Contains the header files of the application (has same folders as `src/` plus):
    - `debug/`: Contains the logger classes for debugging.
    - `interface/`: Contains the interface classes.
  - `config.h`: Contains the configuration settings of the application.
  - `gl_common.h`: Contains the common OpenGL headers.
- `thirdparty/` Contains third-party libraries, such as ImGui and GLAD.
- `assets/`: Contains the assets used in the application (textures, shaders, 3D models).

## Dependencies

- C++ (GNU GCC)
- Meson
- GLFW
- ImGui

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/oop_microwave.git
    ```

2. Build the project using Meson:

    ```bash
    cd oop_microwave
    meson setup builddir .
    ```

3. Compile the project:

    ```bash
    cd builddir
    meson compile -C .
    ```

## Usage

1. Run the application:

    ```bash
    ./builddir/oop_microwave
    ```

2. Follow the on-screen instructions to interact with the microwave. The microwave can cycle between different states: _Door Opened_, _Door Closed_, and _Cooking_. Each state has different behaviors and transitions to other states based on user actions.

## Finite State Machine

The microwave application follows a finite state machine pattern, where it cycles through different states representing the various functionalities of a microwave. The states include `StateDoorOpened`, `StateDoorClosed`, and `StateCooking`. Each state has different behaviors and transitions to other states based on user actions.
