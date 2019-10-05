from afn import AFN
from file_handler import FileHandler

path = "./quintuple.txt"
handler = FileHandler(path)
quintuple = handler.read_file()
afn = AFN(*quintuple)
result = afn.validate("b")
print(result)
