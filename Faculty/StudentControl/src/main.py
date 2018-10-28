from controllers.student_controller import StudentController
from entities.student import Student
from repository.student_repository import StudentRepository
from ui.console import Console

student_repository = StudentRepository()
student_controller = StudentController(student_repository)

# s1 = Student(1, "jon", "913")
# student_controller.add(s1)

console = Console(student_controller)


while __name__ == "__main__":
    console.run_menu()

console.run_menu()
