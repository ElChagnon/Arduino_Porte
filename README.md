<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a>
    <img src="https://i.ibb.co/4dQ48VK/274609016-101069265862986-2731432465316432629-n.webp" alt="Logodemerde" width="200" height="200">
  </a>
  <h1 align="center">Arduino Porte</h1>
  <p align="center">
    Permet ouvrir votre porte via un badge RFID ou un Keypad
  </p>
  
</div>


<div align="center">

##  Les Composants essentiel

</div>

- Arduino Uno
- Led Ou Module Relais 

Seul un des deux est requis pour le fonctionnement du système 

- MFRC522
- Keypad


### Librairie Nécessaire

Vous devez impérativement installer ces librairies pour pouvoir compiler et téléverser sur votre arduino 

* [MFRC522](https://downloads.arduino.cc/libraries/github.com/miguelbalboa/MFRC522-1.4.11.zip?_gl=1*1c2cbgp*_ga*OTgwNjI3MjA0LjE3MTU1OTA0NjQ.*_ga_NEXN8H46L5*MTcxNTU5MDQ2My4xLjEuMTcxNTU5MDQ3Mi4wLjAuMTA4MTk4NTAzMg..*_fplc*Y1dnTkVoSm9vRDA4Y1RtWmtvZFA4dUIwMnNRVSUyRmpuM2ZPWDdRUHhpTTZ6QlJpQUJxMGg5enVBM3pvNE1UQkt5R2dqTzIyZGZNaTRRbHY1SnRMNklCMHFpYmtzOGY0cXd5anNWT2w4dDZIUWolMkZwVHl4QSUyRmVqTVRJayUyRjBGN2clM0QlM0Q.)
* [KeyPad](https://downloads.arduino.cc/libraries/github.com/Chris--A/Keypad-3.1.1.zip)

<div align="center">

## Configuration 
</div>

<a href="https://imgbb.com/"><img src="https://i.ibb.co/wC2bcNp/Capture-d-cran-2024-05-13-105719.png" alt="Capture-d-cran-2024-05-13-105719" border="0"></a>

**Longueur** et **Largeur** sont a modifier si votre Keypad est different du miens

**Led_Verte** et **Led_Rouge** sont a changer si vous utilisez des ports différent 


<a href="https://ibb.co/WfcKsVS"><img src="https://i.ibb.co/sqF3tWL/Capture-d-cran-2024-05-13-110347.png" alt="Capture-d-cran-2024-05-13-110347" border="0"></a>


Vous pouvez changer le mot de passe à rentrer sur KeyPad en changeant la valeur dans mdp. De même, vous pouvez mettre plusieurs badges RFID en mettant leur valeur hexadécimale dans
les emplacements prévus pour

Vous pouvez retrouver la clé hexa décimal de votre carte dans le moniteur série

<div align="center">

## Montage

</div>

Vous pouvez suivre **ce schéma** 

<a href="https://imgbb.com/"><img src="https://i.ibb.co/18Bd2W5/image.png" alt="image" border="0"></a>

Si vous avez du mal avec le schéma voici le [schéma](https://wokwi.com/projects/397760075805598721) sur Wokwi
Fait juste attention Wokwi n'a pas de MFRC522 dans sa simulation donc j'utilise MPU6050 qui a le même nombre de port 

Faut juste avoir un peu imagination et penser que c'est un MFRC522
<div align="center"/>

## Algorigramme 

Dans le cadre ou vous devez utiliser ce projet pour un cours ou autre [voici-ci le logigramme](https://lucid.app/lucidchart/08e580a5-6c49-4177-98fb-2b3c60cd260b/edit?viewport_loc=-18700%2C-525%2C41600%2C19725%2C0_0&invitationId=inv_b4eb7f2f-32ad-4bdc-a8d5-eae84c4a4e80) qui pourra vous aider

<a href="https://ibb.co/3c9sFyN"><img src="https://i.ibb.co/gJL7WMT/Capture-d-cran-2024-05-13-115602.png" alt="Capture-d-cran-2024-05-13-115602" border="0"></a>


## Truc moche

Je me fiche de créditer ce que j'utilise ou autres, débrouillez vous, c'est juste un projet sur mon temps libre que je peux abandonner du jour au lendemain.

Si vous utilisez le projet, pas besoin de me créditer, je suis déjà assez célèbre.

Et pas besoin de don je ne suis pas un mendiant je ne suis que arabe
