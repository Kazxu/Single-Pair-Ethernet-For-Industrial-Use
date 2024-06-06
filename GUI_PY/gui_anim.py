import socket
import threading
from pathlib import Path
from tkinter import Tk, Canvas, Button, PhotoImage, Label
from math import pi, cos, sin
import time

OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / "assets"
ICON_PATH = OUTPUT_PATH / "icon.png"  # ICON PATH

def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

# Global variable to store the socket and connection status
sock = None
connected = False
current_value = 4.0

# Function to receive data from the server
def receive(sock, signal, meter_canvas, needle, status_label, current_value_label, error_label):
    global current_value
    while signal:
        try:
            data = sock.recv(32)
            if not data:
                raise ConnectionError("No data received")
            message = data.decode("utf-8")
            try:
                value = float(message)
                if 4 <= value <= 20:
                    animate_needle(meter_canvas, needle, current_value, value)
                    current_value = value
                    current_value_label.config(text=f"{value:.2f}mA")
                    if value <= 12:
                        current_value_label.config(fg="#00FF00")  # Green
                    elif value <= 16:
                        current_value_label.config(fg="#FFFF00")  # Yellow
                    else:
                        current_value_label.config(fg="#FF0000")  # Red
                error_label.config(text="")
            except ValueError:
                pass
        except (ConnectionError, socket.error):
            status_label.config(text="Not Connected", fg="red")
            error_label.config(text="Connection lost or server not responding.")
            button_1.config(text="Connect")
            connected = False
            break

# Function to animate the needle smoothly
def animate_needle(canvas, needle, start_value, end_value, steps=100, delay=0.01):
    start_angle = 135 + ((start_value - 4) / 16) * 270
    end_angle = 135 + ((end_value - 4) / 16) * 270
    for step in range(steps):
        angle = start_angle + (end_angle - start_angle) * step / steps
        x0, y0 = 250, 250
        length = 200
        x1 = x0 + length * cos(angle * pi / 180)
        y1 = y0 - length * sin(angle * pi / 180)
        canvas.coords(needle, x0, y0, x1, y1)
        time.sleep(delay)

# Function to send a heartbeat to the server
def send_heartbeat():
    global connected
    while connected:
        try:
            sock.send(b"HEARTBEAT")
            time.sleep(5)
        except (socket.error, OSError):
            connected = False
            status_label.config(text="Not Connected", fg="red")
            error_label.config(text="Connection Error.")
            button_1.config(text="Connect")
            break

# Function to connect to the server
def connect_to_server():
    global sock, connected
    if not connected:
        # Get host and port
        host = '10.0.2.15'
        port = 66

        # Attempt connection to server
        try:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.connect((host, port))
            status_label.config(text="Connected", fg="green")
            error_label.config(text="")
            button_1.config(text="Disconnect")
            connected = True

            # Create new thread to wait for data
            receive_thread = threading.Thread(target=receive, args=(sock, True, meter_canvas, needle, status_label, current_value_label, error_label))
            receive_thread.start()

            # Create new thread for heartbeat
            heartbeat_thread = threading.Thread(target=send_heartbeat)
            heartbeat_thread.start()
        except:
            status_label.config(text="Not Connected", fg="red")
            error_label.config(text="Failed to connect to the server.")
            return
    else:
        # Disconnect from the server
        try:
            sock.close()
            status_label.config(text="Not Connected", fg="red")
            button_1.config(text="Connect")
            connected = False
        except:
            status_label.config(text="Error Disconnecting", fg="red")
            error_label.config(text="Error while disconnecting.")
            return

window = Tk()
window.geometry("811x630")
window.configure(bg="#FFFFFF")  # Changed background color to white
window.title("ADIN1110 CLIENT CONCEPT PROTOTYPE")  # Set the window title

# Set the window icon
try:
    icon_image = PhotoImage(file=ICON_PATH)
    window.iconphoto(False, icon_image)
except Exception as e:
    print(f"Could not load icon: {e}")

canvas = Canvas(
    window,
    bg="#FFFFFF",  # Changed background color to white
    height=630,
    width=811,
    bd=0,
    highlightthickness=0,
    relief="ridge"
)
canvas.place(x=0, y=0)

button_1 = Button(
    text="Connect",  # Changed to text button
    bg="#D3D3D3",  # Grayish background
    fg="#000000",  # Black text
    borderwidth=0,
    highlightthickness=0,
    command=connect_to_server,
    relief="flat"
)
button_1.place(
    x=33.0,
    y=226.0,
    width=273.0,
    height=61.0
)

status_label = Label(window, text="Not Connected", fg="red", bg="#FFFFFF", font=("Inter", 20))  # Changed background color to white
status_label.place(x=33, y=160)  # Adjusted the y position to add more spacing

error_label = Label(window, text="", fg="red", bg="#FFFFFF", font=("Inter", 12))  # Error label for displaying error messages
error_label.place(x=33, y=300)  # Position error label below the button

canvas.create_text(
    33.0,
    41.0,
    anchor="nw",
    text="ADIN1110",
    fill="#000000",  # Changed text color to black
    font=("Inter", 40 * -1)
)

# Custom meter implementation
meter_canvas = Canvas(window, width=500, height=500, bg="#FFFFFF", highlightthickness=0)  # Changed background color to white
meter_canvas.place(x=300, y=50)

# Draw the colored arcs for the meter
meter_canvas.create_arc((50, 50, 450, 450), start=135, extent=143.1, style="arc", outline="#00FF00", width=20)  # Green
meter_canvas.create_arc((50, 50, 450, 450), start=278.1, extent=86.4, style="arc", outline="#FFFF00", width=20)  # Yellow
meter_canvas.create_arc((50, 50, 450, 450), start=364.5, extent=40.5, style="arc", outline="#FF0000", width=20)  # Red

# Draw the static parts of the meter
value_positions = [4, 8, 12, 16, 20]
angles = [135, 207.6, 278.1, 364.5, 405]

for i, value in enumerate(value_positions):
    angle = angles[i]
    x0 = 250 + 180 * cos(angle * pi / 180)
    y0 = 250 - 180 * sin(angle * pi / 180)
    x1 = 250 + 200 * cos(angle * pi / 180)
    y1 = 250 - 200 * sin(angle * pi / 180)
    meter_canvas.create_line(x0, y0, x1, y1, width=2)
    meter_canvas.create_text(250 + 220 * cos(angle * pi / 180), 250 - 220 * sin(angle * pi / 180), text=f"{value:.1f}")

# Needle
needle = meter_canvas.create_line(250, 250, 250 + 200 * cos(135 * pi / 180), 250 - 200 * sin(135 * pi / 180), fill="red", width=3)

# Current Label
current_value_label = Label(window, text="4.00mA", fg="white", bg="black", font=("Inter", 20))
current_value_label.place(x=550, y=20, anchor="n")  # Centered above the meter

window.resizable(False, False) # Resizable
window.mainloop()

