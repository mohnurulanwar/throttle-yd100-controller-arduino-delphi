# 🚢 Throttle Control Head YD-100 Interface (Arduino Uno + Delphi)

This project is a simulation interface that connects a physical **Throttle Control Head YD-100** to a **Delphi desktop application** via **Arduino Uno** and serial communication. The system reads throttle analog values and maps them into readable degrees, which are displayed in a user interface for monitoring or simulation purposes.

---

## ⚙️ Components Used

### 🔌 Hardware:
- Throttle Control Head YD-100 (or analog potentiometer for simulation)
- Arduino Uno
- USB Cable

### 💻 Software:
- Arduino IDE
- Delphi with `CPort` serial library
- `UBinaryPacketizer` unit for byte-wise packet handling

---

## 🔁 How It Works

1. The Arduino reads analog throttle values (e.g., forward and reverse lever).
2. It sends the values over serial in the following format:


3. The Delphi application:
- Uses `CPort` to listen on a COM port
- Extracts and splits the data using a custom `UBinaryPacketizer`
- Maps analog values (0–1023) to throttle degree range (e.g., -11.3 to 11)
- Displays them in real time on the GUI

---

## 🧠 Mapping Function

Delphi maps the raw analog data into a desired degree range using this function:

```pascal
function MapRange(Value, FromLow, FromHigh, ToLow, ToHigh: Double): Double;
begin
Result := ((Value - FromLow) / (FromHigh - FromLow)) *
         (ToHigh - ToLow) + ToLow;
end;
