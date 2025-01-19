let square = {
    id1: '', id2: '', id3: '',
    id4: '', id5: '', id6: '',
    id7: '', id8: '', id9: ''
}

let playerTurn = '';
let warning = '';
let playing = false;

reset();

document.querySelector(".reset").addEventListener("click",reset)
document.querySelector(`div[id="id1"]`).addEventListener("click", itemClick)
document.querySelector(`div[id="id2"]`).addEventListener("click", itemClick)
document.querySelector(`div[id="id3"]`).addEventListener("click", itemClick)
document.querySelector(`div[id="id4"]`).addEventListener("click", itemClick)
document.querySelector(`div[id="id5"]`).addEventListener("click", itemClick)
document.querySelector(`div[id="id6"]`).addEventListener("click", itemClick)
document.querySelector(`div[id="id7"]`).addEventListener("click", itemClick)
document.querySelector(`div[id="id8"]`).addEventListener("click", itemClick)
document.querySelector(`div[id="id9"]`).addEventListener("click", itemClick)

function itemClick(event){
    let item = event.target.getAttribute("id");
    if(playing && square[item] === ""){
        square[item] = playerTurn;
        renderSquare();
        togglePlayer();
    }
}

function reset(){
    warning = '';

    let random = Math.floor(Math.random() * 2);
    playerTurn = (random === 0) ? "x" : "o";

    for(let i in square){
        square[i] = "";
    }

    playing = true;

    renderSquare();
    renderInfo();
}

function renderSquare() {
    for (let i in square){
        let item = document.querySelector(`div[id="${i}"]`);
        item.innerHTML = square[i];
    }

    checkGame();
}

function renderInfo() {
    document.querySelector(".vez").innerHTML = playerTurn;
    document.querySelector(".resultado").innerHTML = warning;
}

function togglePlayer(){
    playerTurn = (playerTurn === "x") ? "o" : "x";
    renderInfo();
}

function checkGame(){
    if(checkWinner("x") === true){
        warning = 'O "x" venceu';
        playing = false;
    }
    else if(checkWinner("o") === true){
        warning = 'O "o" venceu';
        playing = false;
    }
    if(isfull() === true){
        warning = 'deu empate';
        playing = false;
    }
}

function checkWinner(player) {
    // Combinando as células para as linhas, colunas e diagonais
    let winningCombinations = [
        ["id1", "id2", "id3"], // linha 1
        ["id4", "id5", "id6"], // linha 2
        ["id7", "id8", "id9"], // linha 3

        ["id1", "id4", "id7"], // coluna 1
        ["id2", "id5", "id8"], // coluna 2
        ["id3", "id6", "id9"], // coluna 3

        ["id1", "id5", "id9"], // diagonal 1
        ["id3", "id5", "id7"]  // diagonal 2
    ];

    // Verificando se algum jogador tem 3 marcas em uma linha, coluna ou diagonal
    for (let combination of winningCombinations) {
        if (square[combination[0]] === player && square[combination[1]] === player && square[combination[2]] === player) {
            return true;
        }
    }

    return false;
}

function isfull() {
    for (let i in square){
        if(square[i] === '') {
            return false;
        }
    }

    return true;
}