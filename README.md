# 🍷 Vinheria Agnello — Sistema de Monitoramento de Luminosidade

Projeto desenvolvido para monitorar a luminosidade do ambiente de armazenamento da Vinheria Agnello, garantindo condições ideais para a conservação dos vinhos.

---

## 📋 Descrição do Projeto

O sistema utiliza um **Arduino UNO** com um sensor **LDR (Light Dependent Resistor)** para medir continuamente a luminosidade do ambiente. Com base nos valores lidos, o sistema classifica o ambiente em três estados e sinaliza visualmente e sonoramente:

| Estado | Condição | Sinal Visual | Sinal Sonoro |
|---|---|---|---|
| ✅ Adequado | Luminosidade baixa (ideal) | 🟢 LED Verde | — |
| ⚠️ Alerta | Luminosidade intermediária | 🟡 LED Amarelo | — |
| 🚨 Crítico | Luminosidade alta demais | 🔴 LED Vermelho | 3 beeps no buzzer |

---

## 🧰 Componentes Utilizados

- Arduino UNO R3
- Sensor LDR
- 1x LED Verde
- 1x LED Amarelo
- 1x LED Vermelho
- 3x Resistores (para os LEDs)
- 1x Resistor de 10kΩ (para o LDR)
- 1x Buzzer
- Protoboard
- Jumpers/Fios

---

## 🔌 Mapeamento de Pinos

| Componente | Pino Arduino |
|---|---|
| Sensor LDR | A0 |
| LED Verde | 5 |
| LED Amarelo | 3 |
| LED Vermelho | 2 |
| Buzzer | 4 |

---

## 📦 Dependências

- **Arduino IDE** (versão 1.8+ ou 2.x) — [Download](https://www.arduino.cc/en/software)
- Nenhuma biblioteca externa necessária (usa apenas funções nativas do Arduino)

---

## 🚀 Como Reproduzir

### Simulação no Tinkercad

1. Acesse [tinkercad.com](https://www.tinkercad.com) e crie uma conta gratuita
2. Clique em **Circuits → Criar novo circuito**
3. Monte o circuito conforme o mapeamento de pinos acima
4. Cole o código disponível em `vinheria_agnello.ino` no editor de código
5. Clique em **Iniciar simulação**
6. Ajuste o valor do LDR arrastando o slider para testar os três estados

### Arduino Físico

1. Instale a **Arduino IDE**
2. Monte o circuito na protoboard conforme o diagrama
3. Conecte o Arduino ao computador via cabo USB
4. Abra o arquivo `vinheria_agnello.ino` na Arduino IDE
5. Selecione a placa: **Ferramentas → Placa → Arduino UNO**
6. Selecione a porta: **Ferramentas → Porta → (porta do seu Arduino)**
7. Clique em **Upload** (→)
8. Abra o **Monitor Serial** (9600 baud) para acompanhar as leituras em tempo real

---

## ⚙️ Lógica de Funcionamento

```
LDR lê luminosidade (0 a 1023)
        │
        ├── valor >= 500 → 🔴 LED Vermelho + 3 beeps no buzzer
        │
        ├── valor >= 300 → 🟡 LED Amarelo
        │
        └── valor < 300  → 🟢 LED Verde
```

> Os valores limites podem ser calibrados no código nas constantes `LUZ_ADEQUADA` e `LUZ_ALERTA` conforme o ambiente real.

---

## 👥 Autores

Projeto desenvolvido como atividade avaliativa — Vinheria Agnello  
Disciplina: Sistemas Embarcados / IoT

---

## 📄 Licença

Este projeto é de uso educacional.


# Nomes dos integramtes e rms

# Leonardo Porto Sodre, rm: 569388
# Leonardo Gomes Golsaves, rm: 569104
# Eduardo Bechara Medeiros Craveiro, rm: 571081

