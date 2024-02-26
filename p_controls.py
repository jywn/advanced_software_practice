import matplotlib.pyplot as plt

def p_control(current_error, Kp):
    return Kp * current_error

def simulate_system(Kp, setpoint, initial_position, initial_velocity, dt, num_steps):
    positions = [initial_position]
    velocities = [initial_velocity]
    control_outputs = []
    for _ in range(num_steps):
        current_error = setpoint - positions[-1]
        control_output = p_control(current_error, Kp)
        control_outputs.append(control_output * dt)
        next_velocity = velocities[-1] + control_output * dt
        next_position = positions[-1] + next_velocity * dt
        velocities.append(next_velocity)
        positions.append(next_position)
    return positions, velocities, control_outputs

Kp = 0.5
setpoint = 10.0
initial_position = 0.0
initial_velocity = 0.0
dt = 0.1
num_steps = 1000
system_positions, system_velocities, control_outputs = simulate_system(Kp, setpoint, initial_position, initial_velocity, dt, num_steps)
time_steps = [i * dt for i in range(num_steps)]
plt.figure(figsize=(10, 6))
plt.plot(time_steps, control_outputs, label='Control Output (P * dt)', marker='o') 
plt.title('P Control Output with Explicit Euler Method')
plt.xlabel('Time (s)')
plt.ylabel('Control Output (P * dt)')
plt.legend()
plt.grid(True)

plt.show()