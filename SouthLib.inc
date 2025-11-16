#if defined _SOUTHLIB_INCLUDED
	#endinput
#endif
#define _SOUTHLIB_INCLUDED

/*
	SOUTH LIB — Controle de HTML no APK
	Chamadas enviam mensagens via WebSocket para o APK.
	O APK deve enviar o WebSocket para o IP do servidor.
*/

// Configura IP/porta do WebSocket
new SouthLib_WS_IP[32] = "127.0.0.1";
new SouthLib_WS_PORT = 7777;

// ============================
// Enviar comando HTML ao APK
// ============================
stock SendClientHTML(playerid, html_link[])
{
    new msg[256];
    format(msg, sizeof msg, "LOAD_HTML|%s", html_link);

    // Envia pelo WebSocket do servidor (sem plugin real — simulação)
    printf("[SouthLib] Enviando ao jogador %d: %s", playerid, msg);

    // Aqui você usaria plugin WebSocket real se tivesse (opcional)
    // Por enquanto apenas printa
    return 1;
}

// ============================
// Mostrar overlay HTML
// ============================
stock ShowClientHTML(playerid)
{
    printf("[SouthLib] SHOW HTML para %d", playerid);
    return 1;
}

// ============================
// Esconder overlay HTML
// ============================
stock HideClientHTML(playerid)
{
    printf("[SouthLib] HIDE HTML para %d", playerid);
    return 1;
}

