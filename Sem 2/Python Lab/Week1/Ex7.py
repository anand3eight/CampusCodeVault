#Power Calculator

time = 15
mass = int(input("Enter Mass of Object : "))
grv = 9.81
force = mass * grv
dist = int(input("Enter Distance : "))
workDone = force * dist
power = workDone/time
print("Power = ", power)
