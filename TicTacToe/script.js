var arrayNum = new Array (9); // 0 = Empty, 1 = Human , 2 = AI

//Set up
init = function(){
   for(var i = 0 ;  i < arrayNum.length; i++)
   {
      arrayNum[i] = 0;
   }
   $('.cube').css("background-image", "url('')");
}

//Prints the Tic Tac Toe Board in term of 0,1,2
printBoard = function(){
   var toString = "";
   var newLine = 0; //Line
   for(var i = 0 ;  i < arrayNum.length; i++)
   {
      if (newLine === 3) {
         toString = toString + "\n";
         newLine = 1;
      }
      else
      {
         newLine++;
      }
      toString = toString + arrayNum[i] + "";
   }
   return toString;
}

//Check the Columns
checkColumn = function(num,turn){
   var i = 0;
   var win = true;
   if (num < 3) { //0,1,2
      var value = 0;
      while(i < 3)
      {
         if(arrayNum[num+value] != turn)
         {
            win = false;
            break;
         }
         value = value + 3;
         i++;
      }
   }
   else if (num > 5) { //6,7,8
      var value = 0;
      while( i < 3)
      {
         if(arrayNum[num-value] != turn)
         {
            win = false;
            break;
         }
         value = value + 3;
         i++;
      }
   }
   else{ //3,4,5
      var value = 3;
      while(i < 3)
      {
         if(arrayNum[num+value] != turn)
         {
            win = false;
            break;
         }
         value = value - 3;
         i++;
      }
   }
   if (win) {
      if (turn === 1) {
         alert("You won!");
      }
      else{
         alert("You lost!");
         init();
         return true;
      }
      init();
   }
   return false
}

//Check Row
checkRow = function (num,turn){
   var win = true;
   if (num < 3) { // 0 1 2
      for(var i = 0 ; i < 3 ; i++)
      {
         if(arrayNum[i] != turn)
         {
            win = false;
            break;
         }
      }
   }
   else if (num > 5) { //6 7 8
      for(var i = 0 ; i < 3 ; i++)
      {
         if(arrayNum[6+i] != turn)
         {
            win = false;
            break;
         }
      }
   }
   else{ // 3 4 5
      for(var i = 0 ; i < 3 ; i++)
      {
         if(arrayNum[3+i] != turn)
         {
            win = false;
            break;
         }
      }
   }
   if (win) {
      if (turn === 1) {
         alert("You won!");
      }
      else{
         alert("You lost!");
         init();
         return true;
      }
      init();
   }
   return false
}

//Check Diagonal
checkDiagonal = function(num,turn){
   var win = true;
   if (num === 0 || num === 4 || num === 8) { // 0 4 8
      for(var i = 0 ; i < 9 ; i = i + 4)
      {
         if(arrayNum[i] != turn)
         {
            win = false;
            break;
         }
      }
   }
   if (win && num === 4) {
      if (turn === 1) {
         alert("You won!");
      }
      else{
         alert("You lost!");
         init();
         return true;
      }
      init();
   }
   if (num === 4) {
      win = true;
   }
   if(num === 2 || num === 4 || num === 6){
      for(var i = 2 ; i < 8 ; i = i + 2)
      {
         if(arrayNum[i] != turn)
         {
            win = false;
            break;
         }
      }
   }
   
   if(num === 1 || num === 3 || num === 5 || num === 7){
      win = false;
   }
   
   if (win) {
      if (turn === 1) {
         alert("You won!");
      }
      else{
         alert("You lost!");
         init();
         return true;
      }
      init();
   }
   return false;
}


//Return value of the square being pressed from the ID taken from the .cube class.
value = function(num){
      if (num === "one") {
         return 0;
      }
      else if (num === "two") {
         return 1;   
      }
      else if (num === "three") {
          return 2;   
      }
       else if (num === "four") {
          return 3;   
      }
      else if (num === "five") {
          return 4;   
      }
      else if (num === "six") {
          return 5;   
      }
      else if (num === "seven") {
          return 6;   
      }
      else if (num === "eight") {
          return 7;   
      }
      else{
          return 8;   
      }     
}

//Return value of which squared was pressed.
toggleAI = function(num){
      if (num === 0) {
         $('.cube#one').css("background-image", "url('oMark.png')");
      }
      else if (num === 1) {
          $('.cube#two').css("background-image", "url('oMark.png')");
      }
      else if (num === 2) {
          $('.cube#three').css("background-image", "url('oMark.png')");
      }
      else if (num === 3) {
          $('.cube#four').css("background-image", "url('oMark.png')");
      }
      else if (num === 4) {
          $('.cube#five').css("background-image", "url('oMark.png')");
      }
      else if (num === 5) {
          $('.cube#six').css("background-image", "url('oMark.png')");
      }
      else if (num === 6) {
          $('.cube#seven').css("background-image", "url('oMark.png')");
      }
      else if (num === 7) {
          $('.cube#eight').css("background-image", "url('oMark.png')");
      }
      else{
          $('.cube#nine').css("background-image", "url('oMark.png')");
      }
      arrayNum[num] = 2;
}

//AI Turn.
AI = function(newChoices){
      //Random
      var number = (newChoices.length); //Variable that holds the number of choices left
      block = (Math.floor((Math.random() * number + 1))) -1; //Random number between 0 to the random number.
      var one = newChoices[block]; //Finds the value at the location in the array
      toggleAI(one); //Toggle at that position in the array.
      var a = checkColumn(one,2);
      var b = checkRow(one,2);
      var c = checkDiagonal(one,2);
      if (a || b || c) {
         return true;
      }
      return false;
}

//Events
$( document ).ready(function() {
   
   init(); //Initial Initializer.
   
   $(".cube").hover(function(){ //Blue outline unless already clicked on.
      var number = value($(this).attr("id"));
      if (arrayNum[number] === 0) {
         $(this).css("border-color", "#4169E1");
      }
   });
   
   $('.cube').mouseleave(function(){ //Leave and put it back to black
      $(this).css("border-color","#000000");
   });
   
   $(".cube").click(function(){
      var number = value($(this).attr("id")); //Gets the value of the .cube cliked.
      if (arrayNum[number] === 0) { //If the number is the array has not been used yet do:
         $(this).css("background-image", "url('xMark.png')");
         arrayNum[number] = 1; //Toggle clicked boolean
         var choices = []; //Create a variable of choices left array.
         checkColumn(number,1);
         checkRow(number,1);
         checkDiagonal(number,1);
         for(var i = 0 ; i <arrayNum.length ; i++) //Fill it with number not toggled.
         {
            if (arrayNum[i] === 0) {
               choices.push(i);
            }
         }
         if (choices.length!=0) { //Call the AI as long as it choices are not empty
            var alreadyChecked = AI(choices);
            if (choices.length === 1 && alreadyChecked === false) {
               alert("Tied Game");
               init();
            }
         }
         else //Game is over and reset game as no more choices left.
         {
            alert("Tied Game");
            init();
         }
      }
   });
   
   $("#reset").hover(function(){
         $(this).css("border-color", "#4169E1");
   });
   
    $('#reset').mouseleave(function(){
      $(this).css("border-color","#000000");
   });
    
   $("#reset").click(function(){
        init();
   });
});