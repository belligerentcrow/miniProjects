let userChoice = Math.floor(Math.random() *2 );
let computerChoice = Math.floor(Math.random() *2 );

if (userChoice === 0){
  console.log('User chose Paper!');
  }else if (userChoice===1){
  console.log('User chose Rock!');
  } else if (userChoice===2){
  console.log('User chose Scissors!');
  }

if (computerChoice === 0){
  console.log('Computer chose Paper!');
  }else if (computerChoice===1){
  console.log('Computer chose Rock!');
  } else if (computerChoice===2){
  console.log('Computer chose Scissors!');
  }
let pcPoints, userPoints;
function youWin(){
  console.log('You win!');
  userPoints++;
};

function pcWins(){
  console.log('The Computer wins!');
  pcPoints++;
}


if (userChoice === computerChoice){
  console.log('It\'s a draw!');
  pcPoints, userPoints = 0.5; 
} else if (userChoice===0&&computerChoice===1){
  youWin();
} else if (userChoice===0&&computerChoice===2){
  pcWins();
} else if (userChoice===1&&computerChoice===0){
  pcWins();
} else if(userChoice===1&&computerChoice===2){
  youWin();
} else if(userChoice===2&&computerChoice===0){
  youWin();
} else if(userChoice===2&&computerChoice===1){
  pcWins();
} else { console.log('Something went wrong...');}

console.log(userChoice,computerChoice);
