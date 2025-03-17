#include "main.h"

void OnPluginsLoaded()
{
	LoadEBot();
}

void OnAmxxAttach()
{
	MF_AddNatives(ebot_natives);

}
void OnAmxxDetach()
{
	
}