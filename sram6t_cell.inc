* ==========================================
* sram6t_cell.inc
* Transistor models + the single 6T cell
* ==========================================

* Transistor models (educational Level-1 models)
.model NMOS NMOS (LEVEL=1 VTO=0.4 KP=120u LAMBDA=0.02)
.model PMOS PMOS (LEVEL=1 VTO=-0.4 KP=50u LAMBDA=0.02)

* One 6T SRAM cell
* Pins: Q QB WL BL BLB VDD GND
.SUBCKT SRAM6T Q QB WL BL BLB VDD GND

* Inverter 1 (drives Q)
MP1 Q QB VDD VDD PMOS W=2u L=1u
MN1 Q QB GND GND NMOS W=2u L=1u

* Inverter 2 (drives QB)
MP2 QB Q VDD VDD PMOS W=2u L=1u
MN2 QB Q GND GND NMOS W=2u L=1u

* Access transistors (bit-line side is the drain)
MA1 BL  WL Q  GND NMOS W=0.5u L=1u
MA2 BLB WL QB GND NMOS W=0.5u L=1u

.ENDS SRAM6T