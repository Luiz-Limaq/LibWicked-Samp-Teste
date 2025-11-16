# 📱 WickLib — HTML Overlay para SAMP Mobile (Android)

WickLib é uma biblioteca nativa utilizada em launchers SAMP Mobile, permitindo ao
servidor exibir interfaces HTML diretamente no cliente Android, sem depender de
navegador externo.

Com ela é possível criar:

- Tela de login personalizada  
- Splash Screen do servidor  
- Inventário  
- Celular completo  
- HUD e menus  
- Loja, doações, painel admin  
- Qualquer interface usando HTML/CSS/JS  

Tudo renderizado **dentro do APK**.

---

# 🚀 Recursos

- Renderização de HTML dentro do jogo  
- Comunicação servidor → cliente via WebSocket  
- Envio de comandos pela linguagem Pawn  
- Overlay transparente por cima do SAMP  
- Suporte a HTML remoto & local  
- Baixo consumo de desempenho  

---

# 📦 Estrutura Geral (sem código interno)

```
/jni
│── Android.mk
│── Application.mk
│── (arquivos nativos compilados da lib)
│── include/wick.h   <- Apenas a interface pública
/java/com/south/lib/
│── SouthBridge.java <- Chamadas JNI públicas
│── JSInterface.java <- Comunicação webview
/pwn/
│── wick.inc         <- Funções Pawn para usar a lib
│── test.pwn         <- Exemplo de uso
```

*Obs: nenhuma parte do código da engine da lib é exposta.*

---

# 🔌 WebSocket — Comunicação

A lib se comunica com o servidor SAMP através de WebSocket.

- O **APK** (cliente) se conecta ao servidor
- O **servidor SAMP** (host) envia mensagens HTML/status
- A lib interpreta e exibe a interface no jogo

Configuração no `wick.inc` (público e seguro):

```
#define WICK_WEBSOCKET_IP   "IP_DO_SERVIDOR"
#define WICK_WEBSOCKET_PORT 8888
```

Você pode usar qualquer host de jogos (Ex: LemeHost, UltraHost, ShockCore).

---

# 📲 Como o Servidor Envia HTML

Através do `wick.inc`, você pode:

### Exibir URL como Splash/Login
```
SendClientURL(playerid, "https://site.com/login.html");
```

### Exibir HTML bruto
```
SendClientHTML(playerid, html_string);
```

### Mostrar/Esconder overlay
```
Wick_Show(playerid);
Wick_Hide(playerid);
```

Isso permite criar interfaces totalmente personalizadas.

---

# 🧪 Exemplo de Script (seguro)

```
public OnPlayerConnect(playerid)
{
    Wick_Show(playerid);
    SendClientURL(playerid, "https://meusite.com/splash.html");
}
```

Nenhuma parte interna é revelada.

---

# 📁 Arquivo wick.inc (interface pública)

Inclui apenas funções Pawn acessíveis ao desenvolvedor:

- `SendClientURL(playerid, url[])`
- `SendClientHTML(playerid, html[])`
- `Wick_Show(playerid)`
- `Wick_Hide(playerid)`

**Nenhuma função nativa/JNI/WebSocket interna aparece aqui.**

---

# 🔒 Segurança

✔ Não expõe código C++  
✔ Não expõe JNI  
✔ Não expõe sistema interno de WebSocket  
✔ Não expõe tratamento da WebView  
✔ Não expõe comunicação nativa  

O README é totalmente seguro para concorrência.

---

# 📌 FAQ

### A lib abre Chrome?
❌ Não.  
Ela usa uma WebView nativa interna.

### Funciona em qualquer servidor?
Sim, basta configurar o IP no `.inc`.

### Posso exibir celular, inventário, loja?
Sim — qualquer interface HTML.

---

# 📞 Suporte

Para integração avançada ou desenvolvimento especializado, contate o mantenedor indicado no projeto.

