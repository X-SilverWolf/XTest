from pymilvus import MilvusClient

# Token form
client = MilvusClient(
    uri="http://localhost:19530",
    token="root:Milvus",
)