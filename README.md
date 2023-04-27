# <p align=center>wgClient
<p align=center>
<a>
    <img alt="Downloads" src="https://img.shields.io/github/downloads/whyghost/wgclient/total">
    <img alt="Repo Size" src="https://img.shields.io/github/repo-size/whyghost/wgclient">
    <img alt="Version" src="https://img.shields.io/github/v/release/whyghost/wgclient?include_prereleases">
    <img alt="Last Commit" src="https://img.shields.io/github/last-commit/whyghost/wgclient">
    <img alt="Last RLS" src="https://img.shields.io/github/release-date-pre/whyghost/wgclient">
    <img alt="Platforms" src="https://img.shields.io/badge/platforms-windows | linux-green">
    <img alt="Fork" src="https://img.shields.io/github/forks/whyghost/wgclient?style=social">
    <img alt="Star" src="https://img.shields.io/github/stars/whyghost/wgclient?style=social">
</a>
</p>

### Project for modding CS 1.6 client.dll (Only for Xash3D) (v1.33 based)

## How To Run

### PC Installation:

#### Windows 
##### (Without Compile)
- You can download from this [link](https://github.com/whyGhosT/wgclient/releases/download/v0.7/client.dll).
- Replace the X:\..\$XashFolder\cstrike\cl_dlls\client.dll with it.
##### (Manual)
- You can create MSVC2017 project with CMake and build them. Check cl_dlls/CMakeLists.txt.
#### Linux
##### (Without Compile)
- You can download from this [link](https://github.com/whyGhosT/wgclient/releases/download/v0.7/client.so).
##### (Manual)
- You can now use CMake for linux make build.
- **If you want build x64 client delete -m32 flag in CMakeLists.txt.**
- **Don't delete -fPIC flag. If you deleted flag, Discord-RPC will give error and you can't compile.**

#### Android Installation:

- You can check [this](https://github.com/hasandramali/wgclient-android).

## Cvars
#### HUD Cvars
```
hud_color "0-255 0-255 0-255"

hud_rainbow "0-1"
hud_rainbow_sat "x"
hud_rainbow_speed "x"
hud_rainbow_val "x"
hud_rainbow_xphase "x.y"
hud_rainbow_yphase "x.y"
hud_rainbow_chat "0-1"

hud_saytext_sound "0-1"
hud_saytext_sound_path "path"
```
#### Bhop Cvars
```
cl_autojump "0-1"
+ducktap
```
#### Other Cvars
```
thirdperson ~ (You can use thirdperson without sv_cheats 1 and multiplayer)

cl_killsound "0-1"
cl_killsound_path "path"

cl_headname "0-1"
```

#### Discord RPC
![resim](https://user-images.githubusercontent.com/81658277/187113567-ef44faf7-0bf9-48e3-8111-b7763f730f09.png)

## Thanks!
[Weimzh's Client](https://github.com/weimzh/cs16-client)

[BlueNightHawk's Client](https://github.com/BlueNightHawk/cs16-client)

[OpenAG](https://github.com/YaLTeR/OpenAG)

[CSMoe](https://github.com/MoeMod/CSMoE)

[PonpiK](https://github.com/ponpik)

[ByOreo](https://github.com/byoreo)

[HasanDramali](https://github.com/hasandramali)
