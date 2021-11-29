const gameTable = {
  lines: {
    line1: [],
    line2: [],
    line3: []
  }
};

function getCard(){
  let newCard = Math.floor(Math.random()*40);
  newCard++;


    if(newCard>0&&newCard<=10){
      newCard = newCard+' di Denaro';
    }else if(newCard>=11&&newCard<=20){
      newCard = (newCard-10)+' di Spade';
    } else if(newCard>=21&&newCard<=30){
      newCard = (newCard-20)+' di Coppe';
    } else if(newCard>=31&&newCard<=40){
      newCard = (newCard-30)+' di Bastoni';
    }
    checkAndInsertCard(newCard);

  };

function checkAndInsertCard(toBeChecked) {
  if(gameTable.lines.line1.includes(toBeChecked)===false&&gameTable.lines.line2.includes(toBeChecked)===false){
    gameTable.lines.line1.push(toBeChecked);
    console.log('Carta estratta! ' + toBeChecked +'!');
    k++;
  }

};

function arrayForming(){
  if(gameTable.lines.line1.length>=6){
    // console.log('line complete!');
    gameTable.lines.line2.push(gameTable.lines.line1.slice(5,6));
    gameTable.lines.line1.pop();
    gameTable.lines.line2 = gameTable.lines.line2.flat();
  }


}

  let k = 0;
  do{
    getCard();
    arrayForming();
  }while (k<10)

console.log(gameTable.lines.line1);
console.log(gameTable.lines.line2);
