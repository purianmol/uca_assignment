const worker = new Worker('worker.js');
const userDiv = document.getElementById("users");

worker.postMessage("start");

worker.onmessage = (data) => {
    console.log(data.data.data.users);
    const users = data.data.data.users;
    userDiv.textContent = "";
    users.forEach(obj => {
        const h1 = document.createElement("h1");
        h1.textContent = obj.firstName;
        userDiv.appendChild(h1);
    });

    
}
