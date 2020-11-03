from afn import AFN
from file_handler import FileHandler
from utils.compere import compere

compere()
path = "./quintuple.txt"
handler = FileHandler(path)
quintuple = handler.read_file()
afn = AFN(*quintuple)
result = afn.validate("+aa.aa")
afn.display_acceptation_paths("+aa.aa")
