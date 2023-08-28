import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class DinoRunGame extends JFrame implements KeyListener {
    private int dinoY;
    private int dinoJumpHeight;
    private boolean isJumping;

    public DinoRunGame() {
        setTitle("Dino Run");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
        setResizable(false);
        setVisible(true);
        addKeyListener(this);
        dinoY = 300;
        dinoJumpHeight = 100;
        isJumping = false;
    }

    public void jump() {
        isJumping = true;
        for (int i = 0; i <= dinoJumpHeight; i++) {
            dinoY--;
            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            repaint();
        }
        for (int i = 0; i <= dinoJumpHeight; i++) {
            dinoY++;
            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            repaint();
        }
        isJumping = false;
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        g.setColor(Color.GREEN);
        g.fillRect(0, 350, getWidth(), getHeight() - 350); // Ground

        g.setColor(Color.RED);
        g.fillRect(100, dinoY, 30, 50); // Dino

        if (isJumping) {
            g.setColor(Color.BLUE);
            g.drawString("Jumping", 10, 20);
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {}

    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_SPACE && !isJumping) {
            jump();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {}

    public static void main(String[] args) {
        SwingUtilities.invokeLater(DinoRunGame::new);
    }
}
