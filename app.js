let boxes=document.querySelectorAll(".box");
let resetb=document.querySelector("#reset");

let n=document.querySelector("#new");
let m=document.querySelector(".mess");
let pa=document.querySelector("#msg");

let turnO=true;
const winPatterns=[
    [0,1,2],
    [3,4,5],
    [6,7,8],
    [0,3,6],
    [1,4,7],
    [2,5,8],
    [0,4,8],
    [2,4,6],
];

const resetGame=()=>{
    turnO=true;
    enableBoxes();
    m.classList.add("hide");
}

boxes.forEach((box)=>
{
    box.addEventListener("click",()=>{
        console.log("box was clicked");
        if(turnO)
        {
            box.innerText="O";
            turnO=false;
        }
        else{
            box.innerText="X";
            turnO=true;
        }
        box.disabled=true;

        checkWinner();
    });
});

const disableBoxes =()=>{
    for(let box of boxes)
    {
        box.disabled=true;
    }
}

const enableBoxes =()=>{
    for(let box of boxes)
    {
        box.disabled=false;
        box.innerText="";
    }
}

const showWinnner=(winner)=>{
    pa.innerText=`Congrtulation,Winner is ${winner}`;
    m.classList.remove("hide");
    disableBoxes();
}


const checkWinner=()=>{
    for(let pattern of winPatterns)
    {
        let p1=boxes[pattern[0]].innerText;
        let p2=boxes[pattern[1]].innerText;
        let p3=boxes[pattern[2]].innerText;

        if(p1!="" && p2!="" && p3!="")
        {
            if(p1===p2 && p2===p3)
            {
            console.log("winner",p1);
        showWinnner(p1);
        }
    }
    }
}

n.addEventListener("click",resetGame);
resetb.addEventListener("click",resetGame);