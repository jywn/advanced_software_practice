import matplotlib.pyplot as plt

def pd_control(current_error, previous_error, Kp, Kd, dt):
    proportional_term = Kp * current_error
    derivative_term = Kd * (current_error - previous_error) / dt
    return proportional_term + derivative_term

def simulate_system(Kp, Kd, setpoint, initial_position, initial_velocity, dt, num_steps):
    positions = [initial_position]
    velocities = [initial_velocity]
    errors = [setpoint - initial_position]
    previous_error = errors[0]
    control_outputs = []
    for i in range(num_steps):
        current_error = setpoint - positions[-1]
        control_output = pd_control(current_error, previous_error, Kp, Kd, dt)
        control_outputs.append(control_output)
        next_velocity = velocities[-1] + control_output * dt
        next_position = positions[-1] + next_velocity * dt
        velocities.append(next_velocity)
        positions.append(next_position)
        errors.append(setpoint - next_position)
        previous_error = current_error
    return positions, velocities, control_outputs

Kp = 0.05
Kd = 0.5
setpoint = 10.0 
initial_position = 0.0
initial_velocity = 0.0
dt = 0.1
num_steps = 1000
system_positions, system_velocities, control_outputs = simulate_system(Kp, Kd, setpoint, initial_position, initial_velocity, dt, num_steps)
time_steps = [i * dt for i in range(num_steps + 1)]
plt.figure(figsize=(10, 6))
plt.plot(time_steps, system_positions, label='System Position', marker='o')
plt.axhline(y=setpoint, color='r', linestyle='--', label='Setpoint')
plt.title('PD Control with Explicit Euler Method')
plt.xlabel('Time (s)')
plt.ylabel('System Position')
plt.legend()
plt.twinx()
plt.plot(time_steps[:-1], control_outputs, label='Control Output', color='g', marker='x')
plt.ylabel('Control Output')
plt.legend()
plt.grid(True)
plt.show()