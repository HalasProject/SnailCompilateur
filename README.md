![alt text](https://raw.githubusercontent.com/HalasProject/SnailCompilateur/master/src/description.png)


Type | Description | Regex 
-----| ------------| ---------
Identifier | Must start with an uppercase followed by at least one alphanum character | `{letter}(_?({letter}\|{digit})+)*` 
Integer number | Composed of at least one digit  |  `[0-9]+`
Real number | Composed of at two integers separated by a point "." |  `[0-9]+\.[0-9]+`

- This langages also accepts the following commands : 

Command | Description | Example 
------- | ----------- | ---------------
Affectation of a number (Integer/Real) to a variable | Set <<identifier>> = <<value>> %. | `Give j 55 %.`
Affectation of the value of a variable to another variable | Get <<identifier>> from <<identifier>> %. | `Get i from j %.`
Condition | If % \<\<condition\>\> % \<\<action\>\> %. | `if % i<j % Set j 55 %.`

