let log = new Log(document.querySelector(".log"));

let char = new Knight("Boma");

let monster = new BigMonster("Monstrengo");  

const stage = new Stage(char, monster, document.querySelector("#char"), document.querySelector("#monster"), log);

stage.start();
