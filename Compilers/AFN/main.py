from afn import AFN
from file_handler import FileHandler
from utils.compere import compere

compere()
path = "./quintuple.txt"
handler = FileHandler(path)
quintuple = handler.read_file()
afn = AFN(*quintuple)
result = afn.validate("+a.a")
afn.display_acceptation_paths("+a.a")
