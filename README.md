# 🐣 Incubadora_Gallinas  
**Autora:** Ana Isabel Guzmán  
**Carné:** 16863  

---

## 📌 Descripción del Proyecto  
Este proyecto consiste en el diseño e implementación de una incubadora digital basada en el microcontrolador **STM32**, orientada al control preciso de **temperatura** y **tiempo** en procesos de incubación.  

El sistema está compuesto por múltiples módulos electrónicos:  
- 🌡️ Sensor de temperatura  
- ⚙️ Servo motor  
- 🔔 Buzzer  
- ⌨️ Teclado matricial  
- 🖥️ Pantalla LCD en modo 4 bits  
- 🔢 Display de 7 segmentos multiplexado  

---

## 🚧 Retos y Soluciones  
Durante el desarrollo se han enfrentado y resuelto desafíos técnicos como:  
- ❌ Errores de compilación  
- 🎛️ Ajustes de contraste sin potenciómetro  
- 🔀 Adaptación de pines según disponibilidad física  

---

## 🔄 Modificaciones Finales  
Al hacer las modificaciones para la **última entrega** (tarala tarala tarala… hubo complicaciones), se presentaron nuevos retos que obligaron a reorganizar parte del código y la lógica de integración de módulos.  

- El proyecto “bueno” y estable quedó bajo el nombre **`gallinasIncub`**.  
- Tras una falla crítica se trabajó en una versión alterna llamada **`Huevos`**, que sirvió como terreno de pruebas y ajustes antes de consolidar la versión final.  

---

## ⚙️ Problema Principal  
El problema principal comenzó con el **cambio e implementación del motor**:  
- La transición hacia el control del servo trajo consigo ajustes en la configuración de **PWM**.  
- Fue necesario realizar **reasignación de pines**.  
- Se requirió sincronizarlo con otros periféricos como el buzzer y el teclado.  

Este cambio desencadenó una serie de incompatibilidades y errores que exigieron depuración minuciosa, pruebas iterativas y documentación detallada para garantizar que el motor funcionara de manera estable dentro del sistema completo.  

---

## ✅ Conclusiones  
La incubadora digital no solo representa un avance en el control de procesos de incubación, sino también un ejemplo de **resiliencia técnica**:  
- Cada complicación —desde el contraste del LCD hasta la integración del motor— se convirtió en una oportunidad para fortalecer el diseño modular.  
- Se mejoró la defendibilidad del código.  
- Se consolidó un proyecto **robusto y funcional**.  
