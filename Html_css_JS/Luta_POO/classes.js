class Personagem{
    _name;
    _fullLife;
    _life;
    _atkPower;
    _defPower;

    constructor(name){
        this._name = name;
    }

    get life(){
        return this._life;
    }

    get fullLife(){
        return this._fullLife;
    }

    get name(){
        return this._name;
    }
    get atkPower(){
        return this._atkPower;
    }

    get defPower(){
        return this._defPower;
    }


    set life(life){
        this._life = life < 0 ? 0 : life;
    }



}

class Knight extends Personagem{
    constructor(name){
        super(name);   
        this._fullLife = 100;
        this._atkPower = 10;
        this._defPower = 8;
        this._life = this.fullLife;
    }
}

class Sorcerer extends Personagem{
    constructor(name){
        super(name);   
        this._fullLife = 80;
        this._atkPower = 15;
        this._defPower = 3;
        this._life = this.fullLife;
    }
}

class LittleMonster extends Personagem{
    constructor(name){
        super(name);   
        this._fullLife = 40;
        this._atkPower = 4;
        this._defPower = 4;
        this._life = this.fullLife;
    }
}

class BigMonster extends Personagem{
    constructor(name){
        super(name);   
        this._fullLife = 120;
        this._atkPower = 16;
        this._defPower = 6;
        this._life = this.fullLife;
    }
}

class Stage{
    constructor(fighter1, fighter2, fighter1El, fighter2El, logObject){
        this._fighter1 = fighter1;
        this._fighter2 = fighter2
        this._fighter1El = fighter1El;
        this._fighter2El = fighter2El;
        this.log = logObject;
    }

    start(){
        this.update();
        this._fighter1El.querySelector("#char .attackbutton").addEventListener("click", () => this.doAttack(this._fighter1, this._fighter2))
        this._fighter2El.querySelector("#monster .attackbutton").addEventListener("click", () => this.doAttack(this._fighter2, this._fighter1))
    }

    update(){
        //fighter 1
        this._fighter1El.querySelector("#char .name").innerHTML = `${this._fighter1.name} - ${this._fighter1.life.toFixed(1)} HP`
        let bar1pctg = (this._fighter1.life / this._fighter1.fullLife) * 100;
        this._fighter1El.querySelector("#char .bar").style.width = `${bar1pctg}%`;

        //fighter 2
        this._fighter2El.querySelector("#monster .name").innerHTML = `${this._fighter2.name} - ${this._fighter2.life.toFixed(1)} HP`;
        let bar2pctg = (this._fighter2.life / this._fighter2.fullLife) * 100;
        this._fighter2El.querySelector("#monster .bar").style.width = `${bar2pctg}%`
    }

    doAttack(attacking, attacked){

        if(attacking.life <= 0 || attacked.life  <= 0){
            this.log.addMessage("Não foi possível atacar, pois alguém está morto")
            return;
        }

        let attackFactor = (Math.random() * 2).toFixed(2);
        let defenseFactor = (Math.random() * 2).toFixed(2);

        let actualAttack = attacking.atkPower * attackFactor;
        let actualDefense = attacked.defPower * defenseFactor;
       
        if(actualAttack > actualDefense){
            attacked.life -= actualAttack;
            this.log.addMessage(`${attacking.name} causou ${actualAttack.toFixed(2)} de dano no ${attacked.name}`)
        }
        else{
            this.log.addMessage(`${attacked.name} conseguiu defender!`)
        }

       this.update();
    }

}

class Log{
    list = [];

    constructor(listEl){
        this.listEl = listEl
    }

    addMessage(msg){
        this.list.push(msg);
        this.render();
    }

    render(){
        this.listEl.innerHTML = '';

        for (let i in this.list){
            this.listEl.innerHTML += `<li>${this.list[i]}</li>`
        }
    }
}