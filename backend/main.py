import cc_utils
from fastapi import FastAPI, Request

app = FastAPI()

@app.get("/stats")
async def get_stats():
    cpu_usage = cc_utils.get_cpu_usage()
    return {
        "cpu_usage": cpu_usage,
        "mem": {
            "mem_usage": cc_utils.get_mem_usage(),
            "total_mem": cc_utils.get_total_mem(),
            "free_mem": cc_utils.get_free_mem()
        },
        "storage": {
            "storage_usage": cc_utils.get_storage_usage(),
            "total_storage": cc_utils.get_total_storage(),
            "free_storage": cc_utils.get_free_storage()
        }
    }   