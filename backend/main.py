import panelutils 
from pathlib import Path
from fastapi import FastAPI, Request
from fastapi.responses import FileResponse
from fastapi.staticfiles import StaticFiles

app = FastAPI()

FRONTEND_DIR = Path(__file__).resolve().parent.parent / "frontend"

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

app.mount("/", StaticFiles(directory=FRONTEND_DIR, html=True), name="frontend")
