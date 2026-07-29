async function fetchData(){
   try {
    const data = await fetch("https://dummyjson.com/users");
    if (!data.ok) {
        throw new Error(`HTTP Error: ${response.status}`);
    }
    
    const formatted = await data.json();
    if (!formatted || formatted.length === 0) {
        throw new Error("No users returned from the API.");
    }


    self.postMessage({
        status:404,
        data:formatted
    });
   } catch (error) {
        self.postMessage({
            status:404,
            error:error.message
        });
   }

    
}

self.onmessage = async () =>{
    await fetchData();
}