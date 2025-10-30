import tkinter as tk
import paho.mqtt.client as mqtt
import json

# Função chamada ao receber mensagem MQTT
def on_message(client, userdata, msg):
    dados = json.loads(msg.payload.decode())
    labelA.config(text=f"{dados['timeA']}")
    labelB.config(text=f"{dados['timeB']}")

# Configuração da janela
root = tk.Tk()
root.title("Placar IoT - Futebol")
root.geometry("400x200")
root.configure(bg="#222222")  # fundo escuro

# Frame do placar
frame = tk.Frame(root, bg="#444444", bd=5, relief="ridge")
frame.pack(padx=20, pady=40, fill="both", expand=True)

# Time A
label_timeA = tk.Label(frame, text="Time A", font=("Helvetica", 16, "bold"), fg="white", bg="#d32f2f", width=10)
label_timeA.grid(row=0, column=0, padx=10, pady=10)

labelA = tk.Label(frame, text="0", font=("Helvetica", 36, "bold"), fg="white", bg="#d32f2f", width=4)
labelA.grid(row=1, column=0, padx=10, pady=10)

# Separador
label_sep = tk.Label(frame, text=":", font=("Helvetica", 36, "bold"), fg="white", bg="#444444")
label_sep.grid(row=1, column=1, padx=10)

# Time B
label_timeB = tk.Label(frame, text="Time B", font=("Helvetica", 16, "bold"), fg="white", bg="#1976d2", width=10)
label_timeB.grid(row=0, column=2, padx=10, pady=10)

labelB = tk.Label(frame, text="0", font=("Helvetica", 36, "bold"), fg="white", bg="#1976d2", width=4)
labelB.grid(row=1, column=2, padx=10, pady=10)

# Configuração MQTT
client = mqtt.Client()
client.connect("test.mosquitto.org", 1883, 60)
client.subscribe("placarIoT/dados")
client.on_message = on_message
client.loop_start()

root.mainloop()
