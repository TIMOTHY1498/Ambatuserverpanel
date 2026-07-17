import panelutils 
from fastapi import FastAPI, Request

app = FastAPI()

@app.get("/stats")
async def get_stats():
    cpu_usage = panelutils.get_cpu_usage()
    return {
        "cpu_usage": cpu_usage,
        "mem": {
            "mem_usage": panelutils.get_mem_usage(),
            "total_mem": panelutils.get_total_mem(),
            "free_mem": panelutils.get_free_mem()
        },
        "storage": {
            "storage_usage": panelutils.get_storage_usage(),
            "total_storage": panelutils.get_total_storage(),
            "free_storage": panelutils.get_free_storage()
        }
    }   

@app.get("/")
async def get_index(request: Request):
    return {
        "message": "Welcome to the Ambatus Server Panel API",
        "endpoints": {
            "/stats": "Get system statistics (CPU, memory, storage)",
            "/": "Get this index message"
        }
    }