def format_sign(width, message):
    words = message.split()
    lines = []
    current_line = []
    current_width = 0

    for word in words:
        if current_width + len(word) + len(current_line) > width:
            lines.append(current_line)
            current_line = []
            current_width = 0

        current_line.append(word)
        current_width += len(word)

    lines.append(current_line)

    for line in lines:
        total_spaces = width - sum(len(word) for word in line)
        num_gaps = len(line) - 1

        if num_gaps == 0:
            print(".".join(line).ljust(width, '.'))
        else:
            spaces_per_gap = total_spaces // num_gaps
            extra_spaces = total_spaces % num_gaps

            formatted_line = ""
            for i, word in enumerate(line):
                formatted_line += word
                if i < num_gaps:
                    formatted_line += "." * (spaces_per_gap + (1 if i < extra_spaces else 0))

            print(formatted_line)

width = int(input())
format_sign(width, 'WELCOME TO CCC GOOD LUCK TODAY')
