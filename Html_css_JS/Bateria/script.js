document.body.addEventListener("keydown", apertou)

document.querySelector("#play").addEventListener("click",() => {
    const input = document.querySelector("#caixa").value;

    if(input !== ""){
        let inputArray = input.split("");
        tocarComposicao(inputArray);
    }
    
})

function apertou(event){

    if(event.key >= 1 && event.key <= 9){
        tocarSom(event.key);
        mostrar(event.key);
    }
}

function tocarSom(tecla){
    const audio = document.querySelector(`#audio${tecla}`);
    if(audio){
        audio.currentTime = 0;
        audio.play();
    }
}

function mostrar(tecla){
    const numero = document.querySelector(`div[id="${tecla}"]`);
    if(numero){
        numero.style.color = "yellow";
        numero.style.borderColor = "yellow";
    }

     // Adiciona uma cor de destaque temporária para visualização do usuário
     setTimeout(() => {
        if (numero) {
            numero.style.color = ""; // Remove a cor do texto
            numero.style.borderColor = ""; // Remove a cor da borda
        }
    }, 200); // Retorna ao normal após 200ms

}

function tocarComposicao(inputArray){
    let wait = 0
    
    for (let i = 0; i < inputArray.length; i++) {
        const tecla = inputArray[i]; // Pega o valor real da tecla

        setTimeout(() => {
            tocarSom(tecla);  // Passa o valor da tecla
            mostrar(tecla);   // Passa o valor da tecla
        }, wait);

        wait += 250; // Atraso de 250ms para a próxima tecla
    }
}
