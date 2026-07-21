let url = window.location.href;

async function getServerStatus() {
    const response = await fetch(url + "/status");
    const data = await response.json();
    // Update the UI with the server status data

    document.getElementById("cpu_total_usage").innerText = data.status;
}
