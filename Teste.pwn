#include <a_samp>
#include "SouthLib.inc"

public OnGameModeInit()
{
    print("[SouthLib] Teste iniciado.");
    return 1;
}

public OnPlayerConnect(playerid)
{
    print("[SouthLib] Jogador entrou. Enviando splash…");

    // Envia o HTML para o jogador
    SendClientHTML(playerid, "https://meusite.com/splash.html");

    // Mostra a tela HTML
    ShowClientHTML(playerid);

    // Fecha automaticamente em 5 segundos
    SetTimerEx("FecharSplash", 5000, false, "i", playerid);

    return 1;
}

forward FecharSplash(playerid);
public FecharSplash(playerid)
{
    HideClientHTML(playerid);
    SendClientMessage(playerid, 0x00FF00AA, "Splash fechada!");
    return 1;
}

