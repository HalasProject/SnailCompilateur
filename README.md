![alt text](https://raw.githubusercontent.com/HalasProject/SnailCompilateur/master/src/description.png)

Pour rouvrir ce projet de preferance avoir Visual Studio , accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

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
`Set i` 23 %.   
`Snl_Real` Aft34_2 %.       
If % i<j % `Set` Aft_5 10 %.      
Else       
Start            
`Get` j from i %.    
`Set` Af34_2 123.54 %.             
`Finish`    
`Snl_Put` "Ceci est une chaine de caractere" %.    
`Snl_Put` i %.     
%.. Ceci est un commentaire     
`Snl_Close`     
