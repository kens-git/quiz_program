A generically titled Quiz Program that reads in questions from csv files and presents them to the user. Inspired by my habit of taking extensive notes and then never reading them, now, they can be reviewed in the form of a quiz.<br/>

Quizzes can be create by either specifying a single file, multiple files, a single directory (recursively), or multiple directories (recursively). Specifying filenames results in the program recursively searching the root 'categories' directory until it finds the first instance of the filename, so it's not recommended to have duplicate filenames.

<h3>CSV file layout</h3>

The QuizParser uses CSVparser to read in the questions from column one and the answers from column two of each row, so the csv file should look like this:<br/>

<table class="border">
    <tr>
        <th></th><th>A</th><th>B</th>
    </tr>
    <tr>
        <td>1</td>
        <td>Question 1</td>
        <td>Answer 2</td>
    </tr>
    <tr>
        <td>2</td>
        <td>Question 2</td>
        <td>Answer 2</td>
    </tr>
    <tr>
        <td>3</td>
        <td>Question 3</td>
        <td>Answer 3</td>
    </tr>
</table>

<h3>CLI example usage:</h3>

<table>
    <tr>
        <td>./quiz 0 filename.csv</td>
        <td>all questions from filename.csv</td>
    </tr>
    <tr>
        <td>./quiz 10 filename.csv</td>
        <td>10 questions from filename.csv</td>
    </tr>
    <tr>
        <td>./quiz 25 filename1.csv filename2.csv</td>
        <td>25 questions from multiple files</td>
    </tr>
    <tr>
        <td>./quiz 0 /path/to/dir</td>
        <td>all questions from all files from the specified directory</td>
    </tr>
    <tr>
        <td>./quiz 0 /path &nbsp;/otherpath </td>
        <td>all questions from specified directories</td>
    </tr>
</table>