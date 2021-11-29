const textElement = document.getElementById('text');
const optionButtonsElement = document.getElementById('option-buttons');

let state = {}

function startGame(){
  state = {}
  showTextNode(1)

}

function showTextNode(textNodeIndex){
  const textNode = textNodes.find(textNode => textNode.id === textNodeIndex)
  textElement.innerText = textNode.text
  while (optionButtonsElement.firstChild){
    optionButtonsElement.removeChild(optionButtonsElement.firstChild)
  }

  textNode.options.forEach(option =>{
    if (showOption(option)){
      const button = document.createElement('button')
      button.innerText = option.text
      button.classList.add('btn')
      button.addEventListener('click', ()=> selectOption(option))
      optionButtonsElement.appendChild(button)
      talkMeUp();
    }

  })
}

function showOption(option){
  return option.requiredState == null || option.requiredState(state)

}

function selectOption(option){
  const nextTextNodeId = option.nextText
  if (nextTextNodeId <=0){
    return startGame()
  }
  state = Object.assign(state,option.setState)
  showTextNode(nextTextNodeId)
}

const textNodes = [
  {id:1,
  text: 'You wake up. Hello.',
  options: [{text:'i am the first choice', setState:{sword:true}, nextText:2},
{text:'i am the second choice', nextText:2}]},
  {id:2,
  text: 'This is a good choice. Now....',
  options:[{text:'i am the third',nextText:3},{text:'i am the fourth', nextText:3}]},
  {id:3, text: 'I haven\'t yet been written.'},
]

function talkMeUp(){
      const myStuff=['Boolean(sword)'];
      let inventory = document.getElementById('description')
      inventory.innerText = `My stuff is... ${myStuff}`
}


startGame();
