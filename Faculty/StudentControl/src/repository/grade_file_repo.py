from repository.student_repository import StudentRepository


class FileRepository(GradeRepository):
    def __init__(self, fileName):
        self.fileName = fileName
        StudentRepository.__init__(self)

    def read_from_file(self):
        pass

    def write_to_file(self):
        pass
