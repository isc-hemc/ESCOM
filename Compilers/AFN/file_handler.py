from typing import List, Tuple


class FileHandler:
    """File Handler.

    This class handles everything that has to do with the file where the
    automaton quintuple is located; the purpose of this class it's to read the
    automaton quintuple file, clean it from any `special character` stored in
    the file (like the backslash for example) and build the quintuple in a
    comprehensive tuple for the program `(states, alphabet, start_state,
    accept_states, transitions)`.

    Attributes
    ----------
    path: str
        Path where the quintuple file is located.

    """

    __slots__ = ("path",)

    def __init__(self, path: str):
        """Constructor."""
        self.path: str = path

    def read_file(self) -> Tuple:
        """Read file.

        Reads the file in the `path` attribute.

        Returns
        -------
        Tuple
            An AFN quintuple.

        """
        with open(self.path, "r") as f:
            data: List = f.readlines()
        data = self.clean_data(data)
        return self.build_quintuple(data)

    def build_quintuple(self, data: List) -> Tuple:
        """Build Quintuple.

        From the data collected from the file in the `path` attribute builds
        the automata quintuple.

        Parameters
        ----------
        data: List
            Raw data readed for the file in the `path` attribute.

        Returns
        -------
        Tuple
            Automata quintuple.

        """
        states: List = data.pop(0).split(",")
        alphabet: List = data.pop(0).split(",")
        start_state: str = data.pop(0)
        accept_states: List = data.pop(0).split(",")
        transitions: List = [element.split(",") for element in data]
        return (states, alphabet, start_state, accept_states, transitions)

    def clean_data(self, data: List) -> List:
        """Clean data.

        Removes the backslash character for each element into a list.

        Parameters
        ----------
        data: List
            Raw data readed for the file in the `path` attribute.

        Returns
        -------
        List

        """
        return [element.rstrip() for element in data]
