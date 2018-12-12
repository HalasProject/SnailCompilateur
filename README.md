![alt text](https://raw.githubusercontent.com/HalasProject/SnailCompilateur/master/Image/description.png)
![Diagramme](https://raw.githubusercontent.com/HalasProject/SnailCompilateur/master/Image/Diagramme.png)
![alt text](https://raw.githubusercontent.com/HalasProject/SnailCompilateur/master/Image/SnailGUI.gif)
       

![alt text](https://raw.githubusercontent.com/HalasProject/SnailCompilateur/master/Image/SnailCommand.jpg)

<p align="center">
 • <a href="LICENSE"><img alt="License" src="https://img.shields.io/badge/license-GPLv3-blue.svg?style=flat-square"></a>
  <img src="http://hits.dwyl.io/Halasproject/SnailCompilateur.svg"/> •
</p>

#### To open this project, preferably have [Visual Studio 2017](https://visualstudio.microsoft.com/fr/vs/), go to File> Open> Project and select the .sln file.

Type | Description | Regex 
-----| ------------| ---------
Identifier | Must start with an uppercase followed by at least one alphanum character | `{letter}(_?({letter}\|{digit})+)*` 
Integer number | Composed of at least one digit  |  `[0-9]+`
Real number | Composed of at two integers separated by a point "." |  `[0-9]+\.[0-9]+`

- This langages also accepts the following commands : 

Command | Description | Example 
------- | ----------- | ---------------
Affectation of a number (Integer/Real) to a variable | Set <<identifier>> = <<value>> %. | `Set j 55 %.`
Affectation of the value of a variable to another variable | Get <<identifier>> from <<identifier>> %. | `Get i from j %.`
Condition | If % \<\<condition\>\> % \<\<action\>\> %. | `if % i<j % Set j 55 %.`


Example of code : 

`Snl_Start`  
`Snl_Int` i,j,Aft_5,f_f_5 %.  
`SnlSt` test "chaine de caractere" %.  
`Set i` 23 %.   
`Snl_Real` Aft34_2 %.       
If % i < j % do `Set` Aft_5 10 %.      
Else       
Start            
`Get` j from i %.    
`Set` Af34_2 123.54 %.             
`Finish`    
`Snl_Put` "Ceci est une chaine de caractere" %.    
`Snl_Put` i %.     
%.. Ceci est un commentaire     
`Snl_Close`     
