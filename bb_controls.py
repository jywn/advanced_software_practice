import matplotlib.pyplot as plt

def bang_bang_control(current_value, setpoint, tolerance, max_output):
    if current_value < setpoint - tolerance:
        return max_output
    else:
        return 0.0

def simulate_system(setpoint, initial_value, tolerance, max_output, max_acceleration, dt, num_steps):
    values = [initial_value]
    velocities = [0.0]
    accelerations = []
    for _ in range(num_steps):
        current_value = values[-1]
        current_velocity = velocities[-1]
        control_output = bang_bang_control(current_velocity, setpoint, tolerance, max_output)
        acceleration = control_output - 0.1
        accelerations.append(acceleration)
        next_velocity = current_velocity + acceleration * dt
        if next_velocity < 0:
            next_velocity = 0
        next_value = current_value + next_velocity * dt
        values.append(next_value)
        velocities.append(next_velocity)
    return values, velocities, accelerations

setpoint = 10.0
initial_value = 0.0
tolerance = 0.5
max_output = 5.0
max_acceleration = 2.0
dt = 0.1
num_steps = 100
system_values, system_velocities, system_accelerations = simulate_system(setpoint, initial_value, tolerance, max_output, max_acceleration, dt, num_steps)
time_steps = [i * dt for i in range(num_steps + 1)]
plt.figure(figsize=(10, 6))
plt.plot(time_steps, system_values, label='System State', marker='o')
plt.axhline(y=setpoint, color='r', linestyle='--', label='Setpoint')
plt.title('Bang-bang Control Simulation with Acceleration')
plt.xlabel('Time (s)')
plt.ylabel('System State')
plt.legend()
plt.grid(True)
plt.show()
plt.figure(figsize=(10, 6))
plt.plot(time_steps, system_velocities, label='System Velocity', marker='o', color='orange')
plt.axhline(y=5.0, color='r', linestyle='--', label='Set Velocity')
plt.title('System Velocity over Time')
plt.xlabel('Time (s)')
plt.ylabel('System Velocity')
plt.legend()
plt.grid(True)
plt.show()
plt.figure(figsize=(10, 6))
plt.plot(time_steps[:-1], system_accelerations, label='System Acceleration', marker='x', color='green')  # 마지막 step은 가속도가 없으므로 제외
plt.title('System Acceleration over Time')
plt.xlabel('Time (s)')
plt.ylabel('System Acceleration')
plt.legend()
plt.grid(True)
plt.show()